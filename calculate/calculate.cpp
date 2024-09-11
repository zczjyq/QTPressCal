#include "ui_mainwindow.h"
#include <mainwindow.h>
#include <cmath>
#include <QDebug>

// 压力计算
void MainWindow::pressureCalculate(double x_m, double y_m, double z_m, double Beta_x
                                   , double Beta_LCG, double S_mm, double s_mm, double L_m
                                   , double D_m, double CB, double CS_m, double T_m
                                   , double delta_t, double V_knot
                                   , double &P1min, double &P1, double &P2) {
    double A1;

    // Longitudinal Distribution of Design Acceleration
    double kv, a_cg, CF, av;
    // Coefficient
    double a, FL, F1, Fa;
    double X_L = x_m / 1000 / L_m;
    double h0 = std::abs(z_m / 1000 - T_m);
    // A1
    A1 = S_mm * s_mm / 1000000;


    CF = std::max(0.2 + 0.6 * std::sqrt(L_m) / V_knot, 0.32);
    a_cg = 0.65 * CF * V_knot / std::sqrt(L_m);
    if (X_L <= 0.4) kv = 0.8;
    else kv = 2 * X_L;
    av = kv * a_cg;

    // a, FL, F1, Fa;
    if (X_L < 0.5) a = 0.036;
    else a = 2 * (0.04 / (CB - 0.024) - 0.036) * X_L + 0.04 / (CB - 0.024) - 2 * (0.04 / (CB - 0.024) - 0.036);
    if (X_L < 0.5) FL = X_L + 0.5;
    else {
        if (X_L < 0.8) FL = 1;
        else FL = -2/5 * X_L + 3;
    }
    F1 = std::max((50 - Beta_x) / (50 - Beta_LCG), 0.4);
    Fa = 0.3 - 0.15 * std::log10(1.43 * A1 * T_m / delta_t);

    P1min = D_m * 10;
    P1 = 0.24 * std::sqrt(L_m) * (1 - h0 / (2 * T_m)) + 10 * (h0 + a * L_m);
    P2 =15 * (1 + av) * delta_t / L_m / CS_m * 9.8 * FL * F1 * Fa;
}

void MainWindow::on_calculateButton_clicked()
{
    calculateSize();
    for (int i = 1; i <= size; i ++ ) {
        pressureCalculate(x_m[i], y_m[i], z_m[i]
                          , Beta_x[i], Beta_LCG[i]
                          , S_mm[i], s_mm[i]
                          , L_m, D_m, CB, CS_m, T_m, delta_t, V_knot
                          , P1min[i], P1[i], P2[i]);
    }
    // 计算结果


    // 显示结果
    showPressureResult(P1min[index], P1[index], P2[index]);

    // int size = 19;
    createResultTableInFrame(ui->frameShowResult, size);
}

void MainWindow::calculateSize() {
    int _ = 1;
    size = 1;
    while (_ ++ ) {
        size = _;
        if (x_m[_] > 0.001 || y_m[_] > 0.001 || z_m[_] >= 0.001 || S_mm[_] >= 0.001 || s_mm[_] >= 0.001 || Beta_x[_] >= 0.001 || Beta_LCG[_] >= 0.001) {
            _ ++ ;
        } else {
            break;
        }
        qDebug() << "x_m:" << x_m[_]
                 << " y_m:" << y_m[_]
                 << " z_m:" << z_m[_]
                 << " S_mm:" << S_mm[_]
                 << " s_mm:" << s_mm[_]
                 << " Beta_x:" << Beta_x[_]
                 << " Beta_LCG:" << Beta_LCG[_];
        qDebug() << _ << "\n";
    }
}
