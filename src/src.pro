QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = imViewer
TEMPLATE = app
CONFIG += C++11

TEMPLATE = app

INCLUDEPATH += ./ \
    dialog/ \
    utils/  \
    mainwindow/

HEADERS += dialog/dialog_exp_transform.h \
    dialog/dialog_linear_gray.h \
    dialog/dialog_log_grey.h    \
    dialog/dialog_power_grey.h \
    dialog/dialog_stretch_transform.h   \
    dialog/dialog_two_threshold_transform.h \
    mainwindow/mainwindow.h    \
    mainwindow/graphicsview.h   \
    dialog/dialog_gaussianblur.h  \
    mainwindow/graphicsview.h   \
    utils/histogram.h   \
    utils/medianfilter.h    \
    utils/tools.h   \
    utils/qcustomplot.h   \



SOURCES += dialog/dialog_exp_transform.cpp \
    dialog/dialog_gaussianblur.cpp  \
    dialog/dialog_linear_gray.cpp   \
    dialog/dialog_log_grey.cpp  \
    dialog/dialog_power_grey.cpp    \
    dialog/dialog_stretch_transform.cpp \
    dialog/dialog_two_threshold_transform.cpp   \
    mainwindow/mainwindow.cpp  \
    mainwindow/graphicsview.cpp \
    utils/gaussianblur.cpp  \
    utils/histogram.cpp \
    utils/medianfilter.cpp  \
    utils/qcustomplot.cpp   \
    utils/tools.cpp \
    main.cpp

FORMS    += mainwindow/mainwindow.ui \
    dialog/gaussianblurdialog.ui \
    dialog/dialog_linear_gray.ui \
    dialog/dialog_log_grey.ui \
    dialog/dialog_power_grey.ui \
    dialog/dialog_exp_transform.ui \
    dialog/dialog_two_threshold_transform.ui \
    dialog/dialog_stretch_transform.ui

RESOURCES += \
    res/default.qrc

TRANSLATIONS += res/cn.ts
