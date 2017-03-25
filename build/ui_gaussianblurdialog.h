/********************************************************************************
** Form generated from reading UI file 'gaussianblurdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSSIANBLURDIALOG_H
#define UI_GAUSSIANBLURDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GaussianBlurDialog
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *gaussianSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GaussianBlurDialog)
    {
        if (GaussianBlurDialog->objectName().isEmpty())
            GaussianBlurDialog->setObjectName(QStringLiteral("GaussianBlurDialog"));
        GaussianBlurDialog->resize(254, 98);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GaussianBlurDialog->sizePolicy().hasHeightForWidth());
        GaussianBlurDialog->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(GaussianBlurDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(GaussianBlurDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        gaussianSpinBox = new QSpinBox(GaussianBlurDialog);
        gaussianSpinBox->setObjectName(QStringLiteral("gaussianSpinBox"));
        gaussianSpinBox->setMaximum(200);

        verticalLayout->addWidget(gaussianSpinBox);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        buttonBox = new QDialogButtonBox(GaussianBlurDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(0, QFormLayout::FieldRole, buttonBox);


        retranslateUi(GaussianBlurDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GaussianBlurDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GaussianBlurDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GaussianBlurDialog);
    } // setupUi

    void retranslateUi(QDialog *GaussianBlurDialog)
    {
        GaussianBlurDialog->setWindowTitle(QApplication::translate("GaussianBlurDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("GaussianBlurDialog", "Input value for radius:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GaussianBlurDialog: public Ui_GaussianBlurDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSSIANBLURDIALOG_H
