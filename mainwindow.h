#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qframe.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createResultTableInFrame(QFrame *frame, int size);
    void calculateSize();
private slots:
    // 初始化
    void init();
    void on_pushButton_clicked();

    void on_calculateButton_clicked();

    void pressureCalculate(double x_m, double y_m, double z_m, double Beta_x, double Beta_LCG, double S_mm, double s_mm, double L_m, double D_m, double CB, double CS_m, double T_m, double delta_t, double V_knot, double &P1min, double &P1, double &P2);
    void showPressureResult(double P1min, double P1, double P2);

    void setStarOfValue();
    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_2_clicked();
    void readCsvAndDisplayInFrame(const QString &filePath, QFrame *frame);

    void on_spinBox_valueChanged(int arg1);

    void on_dataInputCheck_clicked();

private:
    Ui::MainWindow *ui;
    double x_m[100], y_m[100], z_m[100];
    double Beta_LCG[100], Beta_x[100];
    double L_m, D_m, CB, CS_m, T_m, delta_t, V_knot;
    double S_mm[100], s_mm[100];
    double P1min[100], P1[100], P2[100];
    int index;
    int size;


    void ERROR_NEGATIVE_VALUE();
    void SUCCESS_SAVE();
};
#endif // MAINWINDOW_H
