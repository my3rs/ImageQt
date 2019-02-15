#include "dialog_linear_gray.h"
#include "ui_dialog_linear_gray.h"

LinearGrayDialog::LinearGrayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinearGrayDialog)
{
    ui->setupUi(this);

//    QPixmap pixmap;
//    pixmap.load(":/img/src/lineGrey.gif");
//    ui->label->setPixmap(pixmap);

    paintFunctionImage(ui->aDoubleSpinBox->value(), ui->bDoubleSpinBox->value());

}

/******************************************************************************
 *                              绘制线性变换函数的图像
 * y = __a*x + __b
 * ***************************************************************************/
void LinearGrayDialog::paintFunctionImage(double __a, double __b)
{
    // generate some data:
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 10; // x goes from -10 to 10
      y[i] = x[i]*__a + __b; // let's plot a quadratic function
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

LinearGrayDialog::~LinearGrayDialog()
{
    delete ui;
}


void LinearGrayDialog::on_buttonBox_accepted()
{
    emit sendData(ui->aDoubleSpinBox->value(), ui->bDoubleSpinBox->value());
}

void LinearGrayDialog::on_aDoubleSpinBox_valueChanged(double arg1)
{
    paintFunctionImage(arg1, ui->bDoubleSpinBox->value());
}

void LinearGrayDialog::on_bDoubleSpinBox_valueChanged(double arg1)
{
    paintFunctionImage(ui->aDoubleSpinBox->value(), arg1);
}
