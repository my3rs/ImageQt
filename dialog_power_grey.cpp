#include "dialog_power_grey.h"
#include "ui_dialog_power_grey.h"

DialogPowerGrey::DialogPowerGrey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPowerGrey)
{
    ui->setupUi(this);

    paintFunctionImage(ui->cDoubleSpinBox->value(), ui->rDoubleSpinBox->value(), ui->bDoubleSpinBox->value());
}

DialogPowerGrey::~DialogPowerGrey()
{
    delete ui;
}

void DialogPowerGrey::on_buttonBox_accepted()
{
    emit sendData(ui->cDoubleSpinBox->value(), ui->rDoubleSpinBox->value(), ui->bDoubleSpinBox->value());
}

void DialogPowerGrey::paintFunctionImage(double c, double r, double b)
{
    // generate some data:
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 10; // x goes from 0 to 20
      y[i] = c*qPow(x[i], r) + b;
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-10, 10);
    ui->customPlot->yAxis->setRange(-10, 10);
    ui->customPlot->replot();
}

void DialogPowerGrey::on_cDoubleSpinBox_valueChanged(double c)
{
    paintFunctionImage(c, ui->rDoubleSpinBox->value(), ui->bDoubleSpinBox->value());
}




void DialogPowerGrey::on_rDoubleSpinBox_valueChanged(double r)
{
    paintFunctionImage(ui->cDoubleSpinBox->value(), r, ui->bDoubleSpinBox->value());
}

void DialogPowerGrey::on_bDoubleSpinBox_valueChanged(double b)
{
    paintFunctionImage(ui->cDoubleSpinBox->value(), ui->rDoubleSpinBox->value(), b);
}
