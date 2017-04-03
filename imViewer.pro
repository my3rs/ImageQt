#-------------------------------------------------
#
# Project created by QtCreator 2017-03-20T14:23:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = imViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    graphicsview.cpp \
    tools.cpp \
    filters.cpp \
    dialog_brightness.cpp \
    dialog_gaussianblur.cpp \
    dialog_zoom.cpp \
    histogram.cpp \
    dialog_linear_gray.cpp \
    qcustomplot.cpp \
    dialog_log_grey.cpp \
    dialog_power_grey.cpp \
    dialog_exp_transform.cpp \
    dialog_two_threshold_transform.cpp

HEADERS  += mainwindow.h \
    image.h \
    graphicsview.h \
    tools.h \
    filters.h \
    dialog_brightness.h \
    dialog_gaussianblur.h \
    dialog_zoom.h \
    histogram.h \
    dialog_linear_gray.h \
    qcustomplot.h \
    dialog_log_grey.h \
    dialog_power_grey.h \
    dialog_exp_transform.h \
    dialog_two_threshold_transform.h

FORMS    += mainwindow.ui \
    zoomdialog.ui \
    gaussianblurdialog.ui \
    dialog_brightness.ui \
    dialog_linear_gray.ui \
    dialog_log_grey.ui \
    dialog_power_grey.ui \
    dialog_exp_transform.ui \
    dialog_two_threshold_transform.ui

RESOURCES += \
    default.qrc

TRANSLATIONS += cn.ts
