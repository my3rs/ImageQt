/****************************************************************************
 *                    Mainwindow and actions control
 *
 * *************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QLabel>
#include <QDebug>
#include <QStandardPaths>
#include <QTranslator>
#include "image.h"
#include "graphicsview.h"
#include "dialog_zoom.h"
#include "dialog_brightness.h"
#include "dialog_gaussianblur.h"c
#include "filters.h"
#include "tools.h"
#include "histogram.h"
#include "dialog_linear_gray.h"
#include "dialog_log_grey.h"
#include "dialog_power_grey.h"
#include "dialog_exp_transform.h"


#define WINDOW_TITLE    "ImageQt"
#define WINDOW_CRITICAL "Error - ImageQt"
#define WINDOW_WARNING  "Notice - ImageQt"
#define WINDOW_ABOUT    "About - ImageQt"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void cleanImage();
    void setActionStatus(bool);
    void adjustZoom();
    void adjustBrightness(int delta);
    void updateRightImage(QImage &image, QPixmap &pixmap);

private slots:

    // 从子对话框中接收数据
    void receiveZoomFactor(int factor);
    void receiveBrightnessDelta(int delta);
    void receiveGaussianFactor(int radius);
    void receiveLinearGreyParameter(double, double);
    void receiveLogGreyParamter(double, double);
    void receivePowerGreyParamter(double, double, double);
    void receiveExpGreyParamter(double, double, double);

    // On action triggered
    void on_actionExit_triggered();         // Exit the program
    void on_actionAdjust_triggered();       // Adjust to fit the window size
    void on_actionClose_triggered();        // Clear both left and right Scene
    void on_actionOpen_triggered(QString imagePath = "");
    void on_actionSave_As_triggered();      // Save as
    void on_actionRestore_triggered();      // Restore to the original image
    void on_actionRight_triggered();        // Rotate Right:90^
    void on_actionLeft_triggered();         // Rotate Left: 90^
    void on_actionNormal_triggered();       // Restore the right image to original size
    void on_actionAbout_triggered();        // Show "About" dialog
//    void on_actionZoom_Out_triggered();     // Zoom out
//    void on_actionZoom_In_triggered();      // Zoom in
    void on_zoomAction_triggered();         // Zoom action with dialog
    void on_actionGaussian_blur_triggered();// Gaussian blur
    void on_actionGrayscale_triggered();    // Grayscale
    void on_actionWarm_triggered();
    void on_actionCool_triggered();
    void on_actionMovie_frame_triggered();
    void on_actionClassic_frame_triggered();
    void on_actionFlower_frame_triggered();
    void on_actionMetal_triggered();
    void on_actionAdjust_brightness_triggered();
    void on_actionChinese_triggered();
    void on_actionHorizontal_triggered();
    void on_actionVertical_triggered();
    void on_actionEnglish_triggered();

    void on_actionHistogram_triggered();

    void on_actionLinear_level_transformation_triggered();

    void on_actionLogarithm_grey_level_transformation_triggered();

    void on_actionPower_transformation_triggered();

    void on_actionExp_transfrom_triggered();

private:
    Ui::MainWindow  *ui;
    QGraphicsScene  *leftScene;
    QGraphicsScene  *rightScene;
    Image           *image;               // The original image
    Image           *rightImage;          // The image to show in right Scene
    QLabel          *size, *zoom;

    void repaintRightScene(QPixmap);
    void repaintRightScene();
    void zoomRightImage(int);
    QString getUserName();
    QString getUserPath();
};

#endif // MAINWINDOW_H
