#include "xlsxdocument.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <ui_mainwindow.h>
#include <mainwindow.h>
#include <QFileDialog>
#include <QTableWidget>


void MainWindow::createResultTableInFrame(QFrame *frame, int size)
{
    // 创建 QTableWidget，行数为数组的大小，列数为3
    int rows = size;
    int cols = 3;  // 3列 (P1, P1min, P2)

    QTableWidget *tableWidget = new QTableWidget(rows, cols, frame);

    // 设置表头
    QStringList headers;
    headers << "P1" << "P1min" << "P2";
    tableWidget->setHorizontalHeaderLabels(headers);

    // 填充数据
    for (int row = 1; row <= rows; ++row) {  // 从索引1开始遍历
        tableWidget->setItem(row - 1, 0, new QTableWidgetItem(QString::number(P1[row])));   // P1数据
        tableWidget->setItem(row - 1, 1, new QTableWidgetItem(QString::number(P1min[row]))); // P1min数据
        tableWidget->setItem(row - 1, 2, new QTableWidgetItem(QString::number(P2[row])));   // P2数据
    }

    // 清空 frame 的布局（如果存在），以防多次添加表格
    if (frame->layout() != nullptr) {
        QLayoutItem *item;
        while ((item = frame->layout()->takeAt(0)) != nullptr) {
            delete item->widget();  // 删除旧的 widget
            delete item;
        }
        delete frame->layout();
    }

    // 使用 QVBoxLayout 来将表格添加到 frame 中
    QVBoxLayout *layout = new QVBoxLayout(frame);
    layout->addWidget(tableWidget);
    frame->setLayout(layout);  // 应用新的布局到 frame
}

