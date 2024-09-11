#include "mainwindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}






// 切换的时候数值也会切换
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    index = arg1;

    // 设定阈值，比如 0.001，任何低于此值的数字将被显示为 0
    double threshold = 0.001;

    // 如果值小于阈值，设置为 0；否则，格式化为 3 位小数
    ui->XlineEdit->setText(x_m[index] < threshold ? "0" : QString::number(x_m[index], 'f', 3));
    ui->YlineEdit->setText(y_m[index] < threshold ? "0" : QString::number(y_m[index], 'f', 3));
    ui->ZlineEdit->setText(z_m[index] < threshold ? "0" : QString::number(z_m[index], 'f', 3));

    ui->Beta_xPrinicipallineEdit->setText(Beta_x[index] < threshold ? "0" : QString::number(Beta_x[index], 'f', 3));
    ui->Beta_LCGprinicipallineEdit->setText(Beta_LCG[index] < threshold ? "0" : QString::number(Beta_LCG[index], 'f', 3));

    ui->S_mmPrinicipallineEdit->setText(S_mm[index] < threshold ? "0" : QString::number(S_mm[index], 'f', 3));
    ui->s_mmprinicipallineEdit->setText(s_mm[index] < threshold ? "0" : QString::number(s_mm[index], 'f', 3));

    // 输出调试信息
    qDebug() << arg1 << "\n";
}


void MainWindow::on_dataInputCheck_clicked()
{

    index = ui->spinBox->value();
    x_m[index] = ui->XlineEdit->text().toDouble();
    y_m[index] = ui->YlineEdit->text().toDouble();
    z_m[index] = ui->ZlineEdit->text().toDouble();

    Beta_x[index] = ui->Beta_xPrinicipallineEdit->text().toDouble();
    Beta_LCG[index] = ui->Beta_LCGprinicipallineEdit->text().toDouble();

    S_mm[index] = ui->S_mmPrinicipallineEdit->text().toDouble();
    s_mm[index] = ui->s_mmprinicipallineEdit->text().toDouble();
    SUCCESS_SAVE();
}

