#include <mainwindow.h>
#include <ui_mainwindow.h>

void MainWindow::init()
{
    ui->outputText->setText("");
    L_m = ui->LPrinicipallineEdit->text().toDouble();
    D_m = ui->DPrinicipallineEdit->text().toDouble();
    CB = ui->CBPrinicipallineEdit->text().toDouble();
    CS_m = ui->CSPrinicipallineEdit->text().toDouble();
    T_m = ui->TPrinicipallineEdit->text().toDouble();
    delta_t = ui->deltaPrinicipallineEdit->text().toDouble();
    V_knot = ui->VknotPrinicipallineEdit->text().toDouble();

    setStarOfValue();
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    setStarOfValue();
}
