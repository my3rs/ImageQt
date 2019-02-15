#include "dialog_two_threshold_transform.h"
#include "ui_dialog_two_threshold_transform.h"

DialogThresholdTransform::DialogThresholdTransform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogThresholdTransform)
{
    ui->setupUi(this);
    paintFunctionImage(ui->T1SpinBox->value(), ui->T2SpinBox->value(), ui->comboBox->currentIndex());
}

DialogThresholdTransform::~DialogThresholdTransform()
{
    delete ui;
}

void DialogThresholdTransform::on_buttonBox_accepted()
{
    emit sendData(ui->T1SpinBox->value(), ui->T2SpinBox->value(), ui->comboBox->currentIndex());
}

void DialogThresholdTransform::paintFunctionImage(int t1, int t2, int option)
// int option:
//      0: 0-255-0
//      1: 255-0-255
{
    QVector<double> x(2560), y(2560); // initialize with entries 0..100
    if (option == 0)
    {
        for (int i=0; i<t1*10; ++i)
        {
            x[i] = i/10.0;
            y[i] = 0;
        }
        for (int i=t1*10; i<t2*10; ++i)
        {
            x[i] = i/10.0;
            y[i] = 255;
        }
        for (int i=t2*10; i<2560; ++i)
        {
            x[i] = i/10.0;
            y[i] = 0;
        }
    }
    else
    {
        for (int i=0; i<t1*10; ++i)
        {
            x[i] = i/10.0;
            y[i] = 255;
        }
        for (int i=t1*10; i<t2*10; ++i)
        {
            x[i] = i/10.0;
            y[i] = 0;
        }
        for (int i=t2*10; i<2560; ++i)
        {
            x[i] = i/10.0;
            y[i] = 255;
        }
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 255);
    ui->customPlot->yAxis->setRange(0, 600);
    ui->customPlot->replot();
}

void DialogThresholdTransform::on_T1SpinBox_valueChanged(int t1)
{
//    qDebug()<<ui->comboBox->currentIndex();
    paintFunctionImage(t1, ui->T2SpinBox->value(), ui->comboBox->currentIndex());
}

void DialogThresholdTransform::on_T2SpinBox_valueChanged(int t2)
{
    paintFunctionImage(ui->T1SpinBox->value(), t2, ui->comboBox->currentIndex());
}

void DialogThresholdTransform::on_comboBox_currentIndexChanged(int index)
{
    paintFunctionImage(ui->T1SpinBox->value(), ui->T2SpinBox->value(), index);
}
