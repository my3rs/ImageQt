#include "dialog_stretch_transform.h"
#include "ui_dialog_stretch_transform.h"

DialogStretchTransform::DialogStretchTransform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStretchTransform)
{
    ui->setupUi(this);
}

DialogStretchTransform::~DialogStretchTransform()
{
    delete ui;
}
