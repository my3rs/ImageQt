/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionNormal;
    QAction *actionAdjust;
    QAction *actionRestore;
    QAction *actionLeft;
    QAction *actionRight;
    QAction *zoomAction;
    QAction *actionGaussian_blur;
    QAction *actionGrayscale;
    QAction *actionWarm;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *buttonLayout;
    QHBoxLayout *leftButtonLayout;
    QPushButton *openBtn;
    QPushButton *closeBtn;
    QPushButton *saveAsBtn;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *zoomInBtn;
    QPushButton *normalBtn;
    QPushButton *zoomOutBtn;
    QHBoxLayout *horizontalLayout_4;
    GraphicsView *leftGraphicsView;
    GraphicsView *rightGraphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuRotate;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/src/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/src/document-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/src/avatar-default.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QStringLiteral("actionZoom_In"));
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QStringLiteral("actionZoom_Out"));
        actionNormal = new QAction(MainWindow);
        actionNormal->setObjectName(QStringLiteral("actionNormal"));
        actionAdjust = new QAction(MainWindow);
        actionAdjust->setObjectName(QStringLiteral("actionAdjust"));
        actionRestore = new QAction(MainWindow);
        actionRestore->setObjectName(QStringLiteral("actionRestore"));
        actionLeft = new QAction(MainWindow);
        actionLeft->setObjectName(QStringLiteral("actionLeft"));
        actionRight = new QAction(MainWindow);
        actionRight->setObjectName(QStringLiteral("actionRight"));
        zoomAction = new QAction(MainWindow);
        zoomAction->setObjectName(QStringLiteral("zoomAction"));
        actionGaussian_blur = new QAction(MainWindow);
        actionGaussian_blur->setObjectName(QStringLiteral("actionGaussian_blur"));
        actionGrayscale = new QAction(MainWindow);
        actionGrayscale->setObjectName(QStringLiteral("actionGrayscale"));
        actionWarm = new QAction(MainWindow);
        actionWarm->setObjectName(QStringLiteral("actionWarm"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(6);
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        leftButtonLayout = new QHBoxLayout();
        leftButtonLayout->setSpacing(6);
        leftButtonLayout->setObjectName(QStringLiteral("leftButtonLayout"));
        openBtn = new QPushButton(centralwidget);
        openBtn->setObjectName(QStringLiteral("openBtn"));

        leftButtonLayout->addWidget(openBtn);

        closeBtn = new QPushButton(centralwidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        leftButtonLayout->addWidget(closeBtn);

        saveAsBtn = new QPushButton(centralwidget);
        saveAsBtn->setObjectName(QStringLiteral("saveAsBtn"));

        leftButtonLayout->addWidget(saveAsBtn);


        buttonLayout->addLayout(leftButtonLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        zoomInBtn = new QPushButton(centralwidget);
        zoomInBtn->setObjectName(QStringLiteral("zoomInBtn"));

        horizontalLayout_2->addWidget(zoomInBtn);

        normalBtn = new QPushButton(centralwidget);
        normalBtn->setObjectName(QStringLiteral("normalBtn"));

        horizontalLayout_2->addWidget(normalBtn);

        zoomOutBtn = new QPushButton(centralwidget);
        zoomOutBtn->setObjectName(QStringLiteral("zoomOutBtn"));

        horizontalLayout_2->addWidget(zoomOutBtn);


        buttonLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(buttonLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        leftGraphicsView = new GraphicsView(centralwidget);
        leftGraphicsView->setObjectName(QStringLiteral("leftGraphicsView"));

        horizontalLayout_4->addWidget(leftGraphicsView);

        rightGraphicsView = new GraphicsView(centralwidget);
        rightGraphicsView->setObjectName(QStringLiteral("rightGraphicsView"));

        horizontalLayout_4->addWidget(rightGraphicsView);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 28));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuRotate = new QMenu(menuTools);
        menuRotate->setObjectName(QStringLiteral("menuRotate"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionGaussian_blur);
        menuEdit->addAction(actionGrayscale);
        menuEdit->addAction(actionWarm);
        menuTools->addAction(menuRotate->menuAction());
        menuTools->addAction(actionRestore);
        menuTools->addAction(zoomAction);
        menuRotate->addAction(actionLeft);
        menuRotate->addAction(actionRight);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", Q_NULLPTR));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save...", Q_NULLPTR));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom In", Q_NULLPTR));
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", Q_NULLPTR));
        actionNormal->setText(QApplication::translate("MainWindow", "Normal", Q_NULLPTR));
        actionAdjust->setText(QApplication::translate("MainWindow", "Adjust", Q_NULLPTR));
        actionRestore->setText(QApplication::translate("MainWindow", "Restore", Q_NULLPTR));
        actionLeft->setText(QApplication::translate("MainWindow", "Left", Q_NULLPTR));
        actionRight->setText(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
        zoomAction->setText(QApplication::translate("MainWindow", "Zoom", Q_NULLPTR));
        actionGaussian_blur->setText(QApplication::translate("MainWindow", "Gaussian blur", Q_NULLPTR));
        actionGrayscale->setText(QApplication::translate("MainWindow", "Grayscale", Q_NULLPTR));
        actionWarm->setText(QApplication::translate("MainWindow", "Warm", Q_NULLPTR));
        openBtn->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        saveAsBtn->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        zoomInBtn->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        normalBtn->setText(QApplication::translate("MainWindow", "Restore", Q_NULLPTR));
        zoomOutBtn->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuRotate->setTitle(QApplication::translate("MainWindow", "Rotate", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
