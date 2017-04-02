#include "dialog_linear_gray.h"
#include "ui_dialog_linear_gray.h"

LinearGrayDialog::LinearGrayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinearGrayDialog)
{
    ui->setupUi(this);

    QPixmap pixmap;
    pixmap.load(":/img/src/lineGrey.gif");
    ui->label->setPixmap(pixmap);
}

LinearGrayDialog::~LinearGrayDialog()
{
    delete ui;
}


void LinearGrayDialog::on_buttonBox_accepted()
{
    emit sendData(ui->aDoubleSpinBox->value(), ui->bDoubleSpinBox->value());
}
