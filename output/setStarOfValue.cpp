#include <mainwindow.h>
#include <ui_mainwindow.h>

void MainWindow::setStarOfValue()
{
    // 设置所有 lineEdit 的文本为 ***
    ui->LPrinicipallineEdit->setText("***");
    ui->DPrinicipallineEdit->setText("***");
    ui->CBPrinicipallineEdit->setText("***");
    ui->CSPrinicipallineEdit->setText("***");
    ui->TPrinicipallineEdit->setText("***");
    ui->deltaPrinicipallineEdit->setText("***");
    ui->VknotPrinicipallineEdit->setText("***");
}
