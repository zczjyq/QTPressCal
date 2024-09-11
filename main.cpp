#include "mainwindow.h"
#include <QApplication>
#include <QFont>

QSize MainWindowSize(1500, 1200);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // 先创建 QApplication 对象

    // 设置全局字体
    QFont font;
    font.setFamily("Arial");    // 设置字体类型
    font.setPointSize(10);      // 设置字体大小
    a.setFont(font);            // 将字体应用到整个应用程序

    MainWindow w;
    w.resize(MainWindowSize); // 设置窗口大小
    w.show();
    return a.exec();
}
