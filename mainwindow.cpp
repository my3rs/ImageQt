#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    leftScene = new QGraphicsScene;
    rightScene = new QGraphicsScene;
    image = NULL;
    rightImage = NULL;
    size = new QLabel;
    zoom = new QLabel;

    leftScene->setBackgroundBrush(QColor::fromRgb(224,224,224));
    ui->leftGraphicsView->setScene(leftScene);
    rightScene->setBackgroundBrush(QColor::fromRgb(224,224,224));
    ui->rightGraphicsView->setScene(leftScene);

    ui->statusBar->addPermanentWidget(size);
    ui->statusBar->addWidget(zoom);

    connect(ui->openBtn, SIGNAL(clicked(bool)),
            this, SLOT(on_actionOpen_triggered()));
    connect(ui->closeBtn, SIGNAL(clicked(bool)),
            this, SLOT(on_actionClose_triggered()));
    connect(ui->saveAsBtn, SIGNAL(clicked(bool)),
            this, SLOT(on_actionSave_As_triggered()));

    connect(ui->zoomInBtn, SIGNAL(clicked(bool)),
            this, SLOT(on_actionZoom_In_triggered()));
    connect(ui->zoomOutBtn, SIGNAL(clicked(bool)),
            this, SLOT(on_actionZoom_Out_triggered()));

    connect(ui->normalBtn, SIGNAL(clicked()),
            this, SLOT(on_actionNormal_triggered()));


    setActionStatus(false);
    setWindowTitle("ImageQt");
    ui->actionEnglish->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;

    if (leftScene)
    {
        delete leftScene;
        leftScene = NULL;
    }
    if (image)
    {
        delete image;
        image = NULL;

    }
    if (size)
    {
        delete size;
        size = NULL;
    }

    if (zoom)
    {
        delete zoom;
        zoom = NULL;
    }
}

/******************************************************************************
 *                        Exit the program
 *
 *****************************************************************************/
void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}



void MainWindow::setActionStatus(bool status)
{
    ui->actionSave->setEnabled(status);
    ui->saveAsBtn->setEnabled(status);
    ui->closeBtn->setEnabled(status);
    ui->zoomInBtn->setEnabled(status);
    ui->zoomOutBtn->setEnabled(status);
    ui->normalBtn->setEnabled(status);
    ui->actionSave_As->setEnabled(status);
}

/******************************************************************************
 *                      Clean image of both Scene
 *
 *****************************************************************************/
void MainWindow::cleanImage()
{
    if (leftScene)
    {
        delete leftScene;
        leftScene = new QGraphicsScene;
        leftScene->setBackgroundBrush(QColor::fromRgb(224,224,224));
        ui->leftGraphicsView->setScene(leftScene);
    }
    if (rightScene)
    {
        delete rightScene;
        rightScene = new QGraphicsScene;
        rightScene->setBackgroundBrush(QColor::fromRgb(224,224,224));
        ui->rightGraphicsView->setScene(rightScene);
    }

    if (image)
    {
        delete image;
        image = NULL;
    }
    if (rightImage)
    {
        delete rightImage;
        rightImage = NULL;
    }

    if (size)
    {
        delete size;
        size = new QLabel;
        ui->statusBar->addPermanentWidget(size);
    }

    if (zoom)
    {
        delete zoom;
        zoom = new QLabel;
        ui->statusBar->addWidget(zoom);
    }

    this->setWindowTitle(WINDOW_TITLE);
    ui->leftGraphicsView->resetTransform();
    ui->rightGraphicsView->resetTransform();
    setActionStatus(false);

}

/******************************************************************************
 *                  Adjust the image size to fit the window
 *
 *****************************************************************************/
void MainWindow::on_actionAdjust_triggered()
{
    // left
    int height = image->height();
    int width = image->width();
    int max_height = ui->leftGraphicsView->height();
    int max_width = ui->leftGraphicsView->width();
    int size,max_size,fact=0;
    double val=0;


    size = qMin(width,height);
    max_size = qMin(max_width,max_height);


    if (size < max_size) {
        while ((size*val) < max_size)
            val = pow(1.2,fact++);
        val = pow(1.2,fact-2);
        ui->leftGraphicsView->setFactor(fact-2);
    }

    else {
        val = 1;
        while ((size*val) > max_size)
            val = pow(1.2,fact--);
        val = pow(1.2,fact+1);
        ui->leftGraphicsView->setFactor(fact+1);
    }

    ui->leftGraphicsView->scale(val,val);


    // right
    height = rightImage->height();
    width = rightImage->width();
    max_height = ui->rightGraphicsView->height();
    max_width = ui->rightGraphicsView->width();
    size = max_size = fact = 0;
    val=0;


    size = qMin(width,height);
    max_size = qMin(max_width,max_height);


    if (size < max_size) {
        while ((size*val) < max_size)
            val = pow(1.2,fact++);
        val = pow(1.2,fact-2);
        ui->rightGraphicsView->setFactor(fact-2);
    }

    else {
        val = 1;
        while ((size*val) > max_size)
            val = pow(1.2,fact--);
        val = pow(1.2,fact+1);
        ui->rightGraphicsView->setFactor(fact+1);
    }

    ui->rightGraphicsView->scale(val,val);


    adjustZoom();
}

/******************************************************************************
 *                            Adjust zoom
 *
 *****************************************************************************/
void MainWindow::adjustZoom()
{
    int num = 100*pow(1.2,ui->rightGraphicsView->getFactor());
    QString percentage = QString::number(num);
    zoom->setText(percentage + "%");
}




/******************************************************************************
 *                      Clean image of both Scene
 *
 *****************************************************************************/
void MainWindow::on_actionClose_triggered()
{
    cleanImage();
}




/******************************************************************************
 *                      Open a image file and show it
 ******************************************************************************
 * Args:
 *      QString imagePath: The abslute path of a image
 *****************************************************************************/
void MainWindow::on_actionOpen_triggered(QString imagePath)
{
    if(imagePath.isEmpty())
    {
        // Automatically detects the current user's home directory
        // And then wait the user to select one image
        imagePath = QFileDialog::getOpenFileName(this, tr("Open image"), getUserPath() + "/Pictures",
                                                 tr("All Files (*);;"
                                                    "All Images (*.bpm *.gif *.jpg *.jpeg *.png *.ppm *.xbm *.xpm);;"
                                                    "Image BPM (*.bpm);;"
                                                    "Image GIF (*.gif);;"
                                                    "Image JPG (*.jpg);;"
                                                    "Image JPEG (*.jpeg);;"
                                                    "Image PNG (*.png);;"
                                                    "Image PPM (*.ppm);;"
                                                    "Image XBM (*.xbm);;"
                                                    "Image XPM (*.xpm);;"));
    }

    if (!imagePath.isEmpty())
    {
        QFile file(imagePath);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr(WINDOW_CRITICAL),
                                  tr("Unable to open image."));
            return;
        }

        // delete previous image
        cleanImage();

        // upload image
        image = new Image(imagePath);
        rightImage = new Image(imagePath);

        leftScene->addPixmap(image->pixmapObject());
        rightScene->addPixmap(rightImage->pixmapObject());


        // settings
        this->setWindowTitle(image->name() + " - ImageQt");

        setActionStatus(true);

        size->setText(QString::number(image->width())
                      + " x " + QString::number(image->height()));

        if (qMax(image->width(),
                 image->height()) > qMin(ui->leftGraphicsView->width(),
                                         ui->leftGraphicsView->height()))
            on_actionAdjust_triggered();
        else
            adjustZoom();

    }
}




/******************************************************************************
 *                          Action : Save as
 *****************************************************************************/
void MainWindow::on_actionSave_As_triggered()
{

    QString newPath = QFileDialog::getSaveFileName(this, tr("Save image"), QString(),
            tr("All files (*);;"
               "Image BPM (*.bpm);;"
               "Image GIF (*.gif);;"
               "Image JPG (*.jpg);;"
               "Image JPEG (*.jpeg);;"
               "Image PNG (*.png);;"
               "Image PPM (*.ppm);;"
               "Image XBM (*.xbm);;"
               "Image XPM (*.xpm);;"));

    if (!newPath.isEmpty()) {

        QFile file(newPath);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr(WINDOW_CRITICAL), tr("Unable to save image."));
            return;
        }

        //Save image to new path
        rightImage->save(newPath);
    }
}



/******************************************************************************
 *                   Restore the image, both size and rotate
 *****************************************************************************/
void MainWindow::on_actionRestore_triggered()
{
    ui->rightGraphicsView->resetTransform();
    ui->rightGraphicsView->setFactor(0);

    ui->leftGraphicsView->resetTransform();
    ui->leftGraphicsView->setFactor(0);

    adjustZoom();
}


/******************************************************************************
 *                              Rotate Right
 *****************************************************************************/
void MainWindow::on_actionRight_triggered()
{
    ui->rightGraphicsView->rotate(90);
}





/******************************************************************************
 *                              Rotate Left
 *****************************************************************************/
void MainWindow::on_actionLeft_triggered()
{
    ui->rightGraphicsView->rotate(-90);
}


/******************************************************************************
 *                              To do
 *****************************************************************************/
void MainWindow::on_actionNormal_triggered()
{
    repaintRightScene();
}



/******************************************************************************
 *                              Dialog: About
 *****************************************************************************/
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox message(QMessageBox::NoIcon, tr(WINDOW_ABOUT), "<h1>ImageQt</h1>"
                                                               "Powered By Qt 5.7.1.");
    message.setIconPixmap(QPixmap(":/img/src/logo_1.png"));
    message.exec();
}

/******************************************************************************
 *                              Action: Zoom Out
 *****************************************************************************/
void MainWindow::on_actionZoom_Out_triggered()
{

    int cur_width = rightImage->width();
    int cur_height = rightImage->height();

    QPixmap newPixmap = rightImage->pixmapObject().scaled(cur_width/1.2, cur_height/1.2);

    rightImage->updatePixmap(newPixmap);


    repaintRightScene(newPixmap);
}
/******************************************************************************
 *                              Action: Zoom In
 *****************************************************************************/
void MainWindow::on_actionZoom_In_triggered()
{

    int cur_width = rightImage->width();
    int cur_height = rightImage->height();

    QPixmap newPixmap = rightImage->pixmapObject().scaled(cur_width*1.2, cur_height*1.2);

    rightImage->updatePixmap(newPixmap);


    repaintRightScene(newPixmap);


}

/******************************************************************************
 *                Repaint the right Scene of the MainWindow
 *****************************************************************************/
void MainWindow::repaintRightScene(QPixmap newPixmap)
{
    if (rightScene) {
        delete rightScene;
        rightScene = new QGraphicsScene;
        rightScene->setBackgroundBrush(QColor::fromRgb(224,224,224));
        ui->rightGraphicsView->setScene(rightScene);
        ui->rightGraphicsView->resetTransform();
    }
    rightScene->addPixmap(newPixmap);
}

//void MainWindow::repaintRightScene(QPixmap *newPixmap)
//{
//    if (rightScene) {
//        delete rightScene;
//        rightScene = new QGraphicsScene;
//        rightScene->setBackgroundBrush(QColor::fromRgb(224,224,224));
//        ui->rightGraphicsView->setScene(rightScene);
//        ui->rightGraphicsView->resetTransform();
//    }
//    rightScene->addPixmap(*newPixmap);
//}

void MainWindow::repaintRightScene()
{
    if (rightScene) {
        delete rightScene;
        rightScene = new QGraphicsScene;
        rightScene->setBackgroundBrush(QColor::fromRgb(224,224,224));
        ui->rightGraphicsView->setScene(rightScene);
        ui->rightGraphicsView->resetTransform();
    }

    rightImage->updatePixmap(image->pixmapObject());
    rightImage->updateImage(image->imageObject());
    rightScene->addPixmap(rightImage->pixmapObject());
}



/******************************************************************************
 *                     on Action tools->zoom triggered
 *****************************************************************************/
void MainWindow::on_zoomAction_triggered()
{
    ZoomDialog *dialog = new ZoomDialog;
    connect(dialog, SIGNAL(sendData(int)), this, SLOT(receiveZoomFactor(int)));
    dialog->show();
}

/******************************************************************************
 *                   Receive data from zoom dialog
 *             and then call the function to done zoom action
 * ----------------------------------------------------------------------------
 * This is a private slot function
 *
 *****************************************************************************/
void MainWindow::receiveZoomFactor(int factor)
{
    qDebug()<<"zoom factor:"<<factor;
    zoomRightImage(factor);

}

/******************************************************************************
 *                       Zoom the right Image
 *****************************************************************************/
void MainWindow::zoomRightImage(int factor)
{
    if (factor != 100)
    {
        int cur_width = rightImage->width();
        int cur_height = rightImage->height();

        QPixmap newPixmap = rightImage->pixmapObject().scaled(cur_width*factor/100, cur_height*factor/100);

        rightImage->updatePixmap(newPixmap);




        repaintRightScene(newPixmap);
    }
    else
    {
        return;
    }
}

/******************************************************************************
 *                       Get the current user name
 *****************************************************************************/
QString MainWindow::getUserName()
{
    QString userPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString userName = userPath.section("/", -1, -1);
    return userName;
}

/******************************************************************************
 *                       Get the current user name
 *****************************************************************************/
QString MainWindow::getUserPath()
{
    QString userPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    return userPath;
}


/******************************************************************************
 *                          Gaussian blur
 *****************************************************************************/
void MainWindow::on_actionGaussian_blur_triggered()
{
    GaussianBlurDialog *dialog = new GaussianBlurDialog;
    connect(dialog, SIGNAL(sendData(int)), this, SLOT(receiveGaussianFactor(int)));
    dialog->show();

}

void MainWindow::receiveGaussianFactor(int radius)
/////////////////////////////////////////////////////////////   TO DO
{
    qDebug()<<"Gaussian factor:"<<radius;

}


/******************************************************************************
 *                              Greyscale
 *****************************************************************************/
void MainWindow::on_actionGrayscale_triggered()
{   
    QImage newImage = Tools::GreyScale(rightImage->imageObject());
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);

}

/******************************************************************************
 *                              Warm
 *****************************************************************************/
void MainWindow::on_actionWarm_triggered()
{
    QImage newImage = Tools::Warm(30, rightImage->imageObject());
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);
}

/******************************************************************************
 *                              Cool
 *****************************************************************************/
void MainWindow::on_actionCool_triggered()
{
    QImage newImage = Tools::Cool(30, rightImage->imageObject());
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);
}


/******************************************************************************
 *                              Add frame
 *****************************************************************************/
void MainWindow::on_actionMovie_frame_triggered()
{
    QImage frame = QImage(":/img/src/frame_3.png");
    QImage newImage = Tools::DrawFrame(rightImage->imageObject(), frame);
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);
}

void MainWindow::on_actionClassic_frame_triggered()
{
    QImage frame = QImage(":/img/src/frame_1.png");
    QImage newImage = Tools::DrawFrame(rightImage->imageObject(), frame);
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);
}

void MainWindow::on_actionFlower_frame_triggered()
{
    QImage frame = QImage(":/img/src/frame_2.png");
    QImage newImage = Tools::DrawFrame(rightImage->imageObject(), frame);
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);
}



/******************************************************************************
 *                Update right image and repaint right scene
 *****************************************************************************/
void MainWindow::updateRightImage(QImage &image, QPixmap &pixmap)
{
    rightImage->updateImage(image);
    rightImage->updatePixmap(pixmap);
    repaintRightScene(rightImage->pixmapObject());
}


/******************************************************************************
 *                          Add metal texture
 *****************************************************************************/
void MainWindow::on_actionMetal_triggered()
{
    QImage newImage = Filters::Metal(rightImage->imageObject());
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);
}

/******************************************************************************
 *                          Adjust Brightness
 *****************************************************************************/
void MainWindow::on_actionAdjust_brightness_triggered()
{
    BrightnessDialog *dialog = new BrightnessDialog;
    connect(dialog, SIGNAL(sendData(int)), this, SLOT(receiveBrightnessDelta(int)));
    dialog->show();
}

void MainWindow::receiveBrightnessDelta(int delta)
{
    qDebug()<<"adjust brightness, delta: "<<delta;
    adjustBrightness(delta);
}

void MainWindow::adjustBrightness(int delta)
{
    QImage newImage = Tools::Brightness(delta, rightImage->imageObject());
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);
}


/******************************************************************************
 *                          Flip Horizontal
 *****************************************************************************/
void MainWindow::on_actionHorizontal_triggered()
{
    QImage newImage = Tools::Horizontal(rightImage->imageObject());
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);
}

/******************************************************************************
 *                          Flip Vertical
 *****************************************************************************/
void MainWindow::on_actionVertical_triggered()
{
    QImage newImage = Tools::Vertical(rightImage->imageObject());
    QPixmap tmpPixmap = QPixmap::fromImage(newImage);

    updateRightImage(newImage, tmpPixmap);
}

/******************************************************************************
 *                          Language support
 *****************************************************************************/
void MainWindow::on_actionEnglish_triggered()
{
    QTranslator translator;
    translator.load(":/language/cn.qm");
    qApp->removeTranslator(&translator);
    ui->retranslateUi(this);
    ui->actionEnglish->setEnabled(false);
    ui->actionChinese->setEnabled(true);
}

void MainWindow::on_actionChinese_triggered()
{
    QTranslator translator;
    translator.load(":/language/cn.qm");
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
    ui->actionChinese->setEnabled(false);
    ui->actionEnglish->setEnabled(true);
}
