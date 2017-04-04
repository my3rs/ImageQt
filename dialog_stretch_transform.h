#ifndef DIALOG_STRETCH_TRANSFORM_H
#define DIALOG_STRETCH_TRANSFORM_H

#include <QDialog>

namespace Ui {
class DialogStretchTransform;
}

class DialogStretchTransform : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStretchTransform(QWidget *parent = 0);
    ~DialogStretchTransform();

private:
    Ui::DialogStretchTransform *ui;
};

#endif // DIALOG_STRETCH_TRANSFORM_H
