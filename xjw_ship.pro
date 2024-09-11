QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
include(3rdparty/qtxlsx/src/xlsx/qtxlsx.pri)
SOURCES += \
    calculate/calculate.cpp \
    excelDataRead.cpp \
    main.cpp \
    mainwindow.cpp \
    output/excelShow.cpp \
    output/output_button.cpp \
    output/setStarOfValue.cpp \
    plot/plot.cpp \
    readdata/input.cpp \
    util/init.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui
# QT += charts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
