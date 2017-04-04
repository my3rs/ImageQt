#include "dialog_stretch_transform.h"
#include "ui_dialog_stretch_transform.h"

DialogStretchTransform::DialogStretchTransform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStretchTransform)
{
    ui->setupUi(this);

    calK();
    paintFunctionImage();
}

DialogStretchTransform::~DialogStretchTransform()
{
    delete ui;
}

void DialogStretchTransform::calK()
{
    x1 = ui->x1->value();
    x2 = ui->x2->value();
    y1 = ui->y1->value();
    y2 = ui->y2->value();

    k1 = y1/1.0/x1;
    k2 = (ui->y2->value()-ui->y1->value())/1.0/(ui->x2->value()-ui->x1->value());
    k3 = (255-ui->y2->value())/1.0/(255-ui->x2->value());

    b2 = y2-k2*x2;
    b3 = 255-k3*255;

    ui->k1->setText(QString::number(k1, 10, 2));
    ui->k2->setText(QString::number(k2, 10, 2));
    ui->k3->setText(QString::number(k3, 10, 2));


}

void DialogStretchTransform::paintFunctionImage()
{
    int x1 = ui->x1->value();
    int x2 = ui->x2->value();
    int y1 = ui->y1->value();
    int y2 = ui->y2->value();

    double b2 = y2-k2*x2;
    double b3 = 255-k3*255;

    QVector<double> x(2560), y(2560); // initialize with entries 0..100
    for (int i=0; i<x1*10; ++i)
    {
      x[i] = i/10;
      y[i] = k1*x[i];
    }
    for (int i=x1*10; i< x2*10; i++)
    {
        x[i] = i/10;
        y[i] = k2*x[i]+b2;
    }
    for (int i=x2*10; i< 2560; i++)
    {
        x[i] = i/10;
        y[i] = k3*x[i]+b3;
    }


    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 255);
    ui->customPlot->yAxis->setRange(0, 255);
    ui->customPlot->replot();
}

void DialogStretchTransform::on_x1_valueChanged(int arg1)
{
    calK();
    paintFunctionImage();
}

void DialogStretchTransform::on_y1_valueChanged(int arg1)
{
    calK();
    paintFunctionImage();
}

void DialogStretchTransform::on_x2_valueChanged(int arg1)
{
    calK();
    paintFunctionImage();
}

void DialogStretchTransform::on_y2_valueChanged(int arg1)
{
    calK();
    paintFunctionImage();
}

void DialogStretchTransform::on_buttonBox_accepted()
{
    emit sendData(x1, x2, k1,k2,k3,b2,b3);
}
