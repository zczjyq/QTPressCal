#include "xlsxdocument.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <ui_mainwindow.h>
#include <mainwindow.h>
#include <QFileDialog>
#include <QTableWidget>


void MainWindow::readCsvAndDisplayInFrame(const QString &filePath, QFrame *frame)
{
    QXlsx::Document xlsx(filePath);  // 读取 Excel 文件

    // 获取 Excel 中的行数和列数
    int rows = xlsx.dimension().rowCount();
    int cols = xlsx.dimension().columnCount();

    if (rows == 0 || cols == 0) {
        qWarning() << "Excel file is empty or invalid.";
        return;
    }

    // 清空之前的布局
    QLayout *oldLayout = frame->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    // 使用 QVBoxLayout 来管理 frame_show 中的布局
    QVBoxLayout *layout = new QVBoxLayout(frame);

    // 创建 QTableWidget 来显示 Excel 数据
    QTableWidget *tableWidget = new QTableWidget(100, 7, frame);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑;
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选择;
    tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); // 可以选中多个目标;
    // 设置表头
    QStringList headers;
    headers  << "S(mm)" << "s(mm)" << "X(mm)" << "Y(mm)" << "Z(mm)" << "βx" << "βLCG";
    tableWidget->setHorizontalHeaderLabels(headers);

    // 遍历 Excel 文件中的所有行和列，从第2行开始
    for (int row = 2; row <= rows; ++row) {
        // 第一列设置为index
        QTableWidgetItem *indexItem = new QTableWidgetItem(QString::number(row - 1));
        tableWidget->setItem(row - 1, 0, indexItem);  // 第一列为 index，列索引为 0

        // 填充剩余的列数据
        for (int col = 1; col <= 7; ++col) {  // 从第2列到第8列，Excel 第1列是数据的第2列
            QXlsx::Cell *cell = xlsx.cellAt(row, col + 1);  // Excel 的列索引从 1 开始
            QString cellData;
            if (cell) {
                // 检查是否为数值类型并格式化为三位小数
                if (cell->value().canConvert<double>()) {
                    double value = cell->value().toDouble();
                    cellData = QString::number(value, 'f', 3);  // 显示三位小数
                } else {
                    cellData = cell->value().toString();  // 处理非数值类型的数据
                }
                QTableWidgetItem *item = new QTableWidgetItem(cellData);
                tableWidget->setItem(row - 2, col - 1, item);  // 填充从第2列到第8列的数据
                qDebug() << QString("Row %1, Col %2: %3").arg(row).arg(col).arg(cellData);
            }
        }
    }


    for (int row = 2; row <= rows; ++ row) {
        QXlsx::Cell *index1 = xlsx.cellAt(row, 1);
        QXlsx::Cell *cell_Smm = xlsx.cellAt(row, 2);  // 假设 S_mm 数据在第6列
        QXlsx::Cell *cell_smm = xlsx.cellAt(row, 3);  // 假设 s_mm 数据在第7列
        QXlsx::Cell *cell_x = xlsx.cellAt(row, 4);  // 假设 x_m 数据在第1列
        QXlsx::Cell *cell_y = xlsx.cellAt(row, 5);  // 假设 y_m 数据在第2列
        QXlsx::Cell *cell_z = xlsx.cellAt(row, 6);  // 假设 z_m 数据在第3列
        QXlsx::Cell *cell_BetaLCG = xlsx.cellAt(row, 7);  // 假设 Beta_LCG 数据在第4列
        QXlsx::Cell *cell_BetaX = xlsx.cellAt(row, 8);  // 假设 Beta_x 数据在第5列


        int index = index1 ? index1->value().toInt() : 0;

        x_m[index] = cell_x ? cell_x->value().toDouble() : 0.0;
        y_m[index] = cell_y ? cell_y->value().toDouble() : 0.0;
        z_m[index] = cell_z ? cell_z->value().toDouble() : 0.0;
        Beta_LCG[index] = cell_BetaLCG ? cell_BetaLCG->value().toDouble() : 0.0;
        Beta_x[index] = cell_BetaX ? cell_BetaX->value().toDouble() : 0.0;
        S_mm[index] = cell_Smm ? cell_Smm->value().toDouble() : 0.0;
        s_mm[index] = cell_smm ? cell_smm->value().toDouble() : 0.0;

        // 打印每行数据的调试信息
        qDebug() << QString("Row %1: x_m = %2, y_m = %3, z_m = %4, Beta_LCG = %5, Beta_x = %6, S_mm = %7, s_mm = %8")
                        .arg(row)
                        .arg(x_m[row - 1])
                        .arg(y_m[row - 1])
                        .arg(z_m[row - 1])
                        .arg(Beta_LCG[row - 1])
                        .arg(Beta_x[row - 1])
                        .arg(S_mm[row - 1])
                        .arg(s_mm[row - 1]);
    }

    // 将 tableWidget 添加到布局
    layout->addWidget(tableWidget);
    frame->setLayout(layout);

    qDebug() << "Excel file reading and display finished.";
}


void MainWindow::on_pushButton_2_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Excel File", "", "Excel Files (*.xlsx)");
    if (!filePath.isEmpty()) {
        readCsvAndDisplayInFrame(filePath, ui->frameShowCSV);  // 调用读取 Excel 并显示的函数
    }
}
