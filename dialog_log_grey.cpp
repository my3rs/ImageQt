#include "dialog_log_grey.h"
#include "ui_dialog_log_grey.h"

DialogLogGrey::DialogLogGrey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogGrey)
{
    ui->setupUi(this);

    QPixmap pixmap;
    pixmap.load(":/img/src/log.png");

    ui->funLabel->setPixmap(pixmap);

    paintFunctionImage(ui->aDoubleSpinBox->value(), ui->bDoubleSpinBox->value());
}

DialogLogGrey::~DialogLogGrey()
{
    delete ui;
}

void DialogLogGrey::on_buttonBox_accepted()
{
    emit sendData(ui->aDoubleSpinBox->value(), ui->bDoubleSpinBox->value());
}

/******************************************************************************
 *                              绘制变换函数的图像
 * y = __a*x + __b
 * ***************************************************************************/
void DialogLogGrey::paintFunctionImage(double __a, double __b)
{
    // generate some data:
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0; // x goes from 0 to 20
      y[i] = qLn(__b + x[i])/qLn(__a);
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 20);
    ui->customPlot->yAxis->setRange(-10, 10);
    ui->customPlot->replot();
}

void DialogLogGrey::on_aDoubleSpinBox_valueChanged(double arg1)
{
    paintFunctionImage(arg1, ui->bDoubleSpinBox->value());
}

void DialogLogGrey::on_bDoubleSpinBox_valueChanged(double arg1)
{
    paintFunctionImage(ui->aDoubleSpinBox->value(), arg1);
}
