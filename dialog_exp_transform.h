#ifndef DIALOG_EXP_TRANSFORM_H
#define DIALOG_EXP_TRANSFORM_H

#include <QDialog>

namespace Ui {
class DialogExpTransform;
}

class DialogExpTransform : public QDialog
{
    Q_OBJECT

public:
    explicit DialogExpTransform(QWidget *parent = 0);
    ~DialogExpTransform();

private:
    Ui::DialogExpTransform *ui;
};

#endif // DIALOG_EXP_TRANSFORM_H
