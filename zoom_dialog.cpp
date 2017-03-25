#include "zoom_dialog.h"
#include "ui_zoomdialog.h"

ZoomDialog::ZoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZoomDialog)
{
    ui->setupUi(this);
}

ZoomDialog::~ZoomDialog()
{
    delete ui;
}

void ZoomDialog::on_buttonBox_accepted()
{
    emit sendData(ui->zoomFactorSpinBox->value());
}
