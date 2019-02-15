#include "dialog_exp_transform.h"
#include "ui_dialog_exp_transform.h"

DialogExpTransform::DialogExpTransform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogExpTransform)
{
    ui->setupUi(this);

    paintFunctionImage(ui->bDoubleSpinBox->value(), ui->cDoubleSpinBox->value(), ui->aDoubleSpinBox->value());
}

DialogExpTransform::~DialogExpTransform()
{
    delete ui;
}

void DialogExpTransform::on_buttonBox_accepted()
{
    emit sendData(ui->bDoubleSpinBox->value(), ui->cDoubleSpinBox->value(), ui->aDoubleSpinBox->value());

}

void DialogExpTransform::paintFunctionImage(double b, double c, double a)
{
    // generate some data:
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 10;
      y[i] = qPow(b, c*(x[i]-a));
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

void DialogExpTransform::on_bDoubleSpinBox_valueChanged(double arg1)
{
    paintFunctionImage(arg1, ui->cDoubleSpinBox->value(), ui->aDoubleSpinBox->value());
}

void DialogExpTransform::on_cDoubleSpinBox_valueChanged(double arg1)
{
    paintFunctionImage(ui->bDoubleSpinBox->value(), arg1, ui->aDoubleSpinBox->value());
}

void DialogExpTransform::on_aDoubleSpinBox_valueChanged(double arg1)
{
    paintFunctionImage(ui->bDoubleSpinBox->value(), ui->cDoubleSpinBox->value(), arg1);
}
