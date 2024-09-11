// #include "qframe.h"
// #include <mainwindow.h>
// #include <ui_mainwindow.h>
// #include <QtCharts/QChartView>   // QChartView 用于显示图表
// #include <QtCharts/QLineSeries>  // QLineSeries 用于折线图的数据
// #include <QtCharts/QChart>       // QChart 用于管理图表
// #include <QVBoxLayout>           // QVBoxLayout 用于布局管理
// #include <QFrame>                // QFrame 容器
// #include <QPainter>              // QPainter 用于抗锯齿


// void MainWindow::createLineChartInFrame(QFrame *frame)
// {
//     // 创建 QLineSeries 来保存数据点
//     QLineSeries *series = new QLineSeries();

//     // 添加数据点 (x, y)
//     series->append(0, 6);
//     series->append(1, 5);
//     series->append(2, 7);
//     series->append(3, 6);
//     series->append(4, 8);
//     series->append(5, 7);
//     series->append(6, 9);

//     // 创建 QChart 来显示 QLineSeries
//     QChart *chart = new QChart();
//     chart->legend()->hide();  // 隐藏图例
//     chart->addSeries(series);  // 将数据系列添加到图表
//     chart->createDefaultAxes();  // 创建默认的X轴和Y轴
//     chart->setTitle("Line Chart in QFrame");

//     // 创建 QChartView 来显示图表
//     QChartView *chartView = new QChartView(chart);
//     chartView->setRenderHint(QPainter::Antialiasing);  // 开启抗锯齿，图形更平滑

//     // 清空 frame 的布局，防止添加多个图表
//     if (frame->layout() != nullptr) {
//         QLayoutItem *item;
//         while ((item = frame->layout()->takeAt(0)) != nullptr) {
//             delete item->widget();  // 删除旧的 widget
//             delete item;
//         }
//         delete frame->layout();
//     }

//     // 创建 QVBoxLayout 并将 QChartView 添加到 frame 中
//     QVBoxLayout *layout = new QVBoxLayout(frame);
//     layout->addWidget(chartView);
//     frame->setLayout(layout);  // 应用布局
// }
