#include "ui_mainwindow.h"
#include <mainwindow.h>

void MainWindow::on_pushButton_clicked()
{
    ui->outputText->setText("");
}

void MainWindow::showPressureResult(double P1min,double P1, double P2)
{
    ui->outputText->setText(QString("运行结果:\n"));  // 显示2位小数
    ui->outputText->append(QString("压力值已完成计算！"));
    ui->outputText->append(QString("\nP1 min: ") + QString::number(P1min));
    ui->outputText->append(QString("\nP1 (Hydrostatic Head): ") + QString::number(P1));
    ui->outputText->append(QString("\nP2 (Impact Pressure): ") + QString::number(P2));
}

void MainWindow::ERROR_NEGATIVE_VALUE() {
    ui->outputText->append(QString("\n索引不能为负！！！"));
}

void MainWindow::SUCCESS_SAVE() {
    ui->outputText->append(QString("\n保存成功"));
}
