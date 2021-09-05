/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButAccept;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout_2;
    QLabel *RFspeaker;
    QLineEdit *lineRFspeaker;
    QLabel *Midrangespeaker;
    QLineEdit *lineMidrangespeaker;
    QLabel *Bassspeaker;
    QLineEdit *lineEditBassspeaker;
    QLabel *Frequencyrange;
    QLineEdit *linefrequencyrane;
    QLabel *Guarantee;
    QSpinBox *spinBxGuarantee;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButReject;
    QFormLayout *formLayout_3;
    QLabel *Country;
    QLineEdit *lineCountry;
    QLabel *Frontpower;
    QSpinBox *spinBxFrontPower;
    QLabel *Frontmaxpower;
    QLineEdit *lineFrontMaxPower;
    QLabel *Frontsensetivity;
    QSpinBox *spinBxFrontsensetivity;
    QLabel *FrontImpedance;
    QSpinBox *spinBxFrontImpedance;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QLabel *Nameoftheaccousticsystem;
    QLineEdit *lineNameACSYS;
    QLabel *Totalratedpower;
    QLineEdit *lineEditTotalratedpower;
    QLabel *totalmaxpower;
    QLineEdit *lineTotalmaxPower;
    QLabel *typeoftheaccousticsystem;
    QLineEdit *linetypeoftheAccSys;
    QLabel *Cost;
    QLineEdit *lineCost;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(637, 447);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButAccept = new QPushButton(Dialog);
        pushButAccept->setObjectName(QString::fromUtf8("pushButAccept"));

        gridLayout->addWidget(pushButAccept, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(174, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        RFspeaker = new QLabel(Dialog);
        RFspeaker->setObjectName(QString::fromUtf8("RFspeaker"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, RFspeaker);

        lineRFspeaker = new QLineEdit(Dialog);
        lineRFspeaker->setObjectName(QString::fromUtf8("lineRFspeaker"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineRFspeaker);

        Midrangespeaker = new QLabel(Dialog);
        Midrangespeaker->setObjectName(QString::fromUtf8("Midrangespeaker"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, Midrangespeaker);

        lineMidrangespeaker = new QLineEdit(Dialog);
        lineMidrangespeaker->setObjectName(QString::fromUtf8("lineMidrangespeaker"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineMidrangespeaker);

        Bassspeaker = new QLabel(Dialog);
        Bassspeaker->setObjectName(QString::fromUtf8("Bassspeaker"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, Bassspeaker);

        lineEditBassspeaker = new QLineEdit(Dialog);
        lineEditBassspeaker->setObjectName(QString::fromUtf8("lineEditBassspeaker"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEditBassspeaker);

        Frequencyrange = new QLabel(Dialog);
        Frequencyrange->setObjectName(QString::fromUtf8("Frequencyrange"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, Frequencyrange);

        linefrequencyrane = new QLineEdit(Dialog);
        linefrequencyrane->setObjectName(QString::fromUtf8("linefrequencyrane"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, linefrequencyrane);

        Guarantee = new QLabel(Dialog);
        Guarantee->setObjectName(QString::fromUtf8("Guarantee"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, Guarantee);

        spinBxGuarantee = new QSpinBox(Dialog);
        spinBxGuarantee->setObjectName(QString::fromUtf8("spinBxGuarantee"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, spinBxGuarantee);


        gridLayout->addLayout(formLayout_2, 1, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(204, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 5, 1, 1);

        pushButReject = new QPushButton(Dialog);
        pushButReject->setObjectName(QString::fromUtf8("pushButReject"));

        gridLayout->addWidget(pushButReject, 2, 4, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        Country = new QLabel(Dialog);
        Country->setObjectName(QString::fromUtf8("Country"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, Country);

        lineCountry = new QLineEdit(Dialog);
        lineCountry->setObjectName(QString::fromUtf8("lineCountry"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineCountry);

        Frontpower = new QLabel(Dialog);
        Frontpower->setObjectName(QString::fromUtf8("Frontpower"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, Frontpower);

        spinBxFrontPower = new QSpinBox(Dialog);
        spinBxFrontPower->setObjectName(QString::fromUtf8("spinBxFrontPower"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, spinBxFrontPower);

        Frontmaxpower = new QLabel(Dialog);
        Frontmaxpower->setObjectName(QString::fromUtf8("Frontmaxpower"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, Frontmaxpower);

        lineFrontMaxPower = new QLineEdit(Dialog);
        lineFrontMaxPower->setObjectName(QString::fromUtf8("lineFrontMaxPower"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineFrontMaxPower);

        Frontsensetivity = new QLabel(Dialog);
        Frontsensetivity->setObjectName(QString::fromUtf8("Frontsensetivity"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, Frontsensetivity);

        spinBxFrontsensetivity = new QSpinBox(Dialog);
        spinBxFrontsensetivity->setObjectName(QString::fromUtf8("spinBxFrontsensetivity"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, spinBxFrontsensetivity);

        FrontImpedance = new QLabel(Dialog);
        FrontImpedance->setObjectName(QString::fromUtf8("FrontImpedance"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, FrontImpedance);

        spinBxFrontImpedance = new QSpinBox(Dialog);
        spinBxFrontImpedance->setObjectName(QString::fromUtf8("spinBxFrontImpedance"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, spinBxFrontImpedance);


        gridLayout->addLayout(formLayout_3, 1, 3, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(149, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        Nameoftheaccousticsystem = new QLabel(Dialog);
        Nameoftheaccousticsystem->setObjectName(QString::fromUtf8("Nameoftheaccousticsystem"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Nameoftheaccousticsystem);

        lineNameACSYS = new QLineEdit(Dialog);
        lineNameACSYS->setObjectName(QString::fromUtf8("lineNameACSYS"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineNameACSYS);

        Totalratedpower = new QLabel(Dialog);
        Totalratedpower->setObjectName(QString::fromUtf8("Totalratedpower"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Totalratedpower);

        lineEditTotalratedpower = new QLineEdit(Dialog);
        lineEditTotalratedpower->setObjectName(QString::fromUtf8("lineEditTotalratedpower"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditTotalratedpower);

        totalmaxpower = new QLabel(Dialog);
        totalmaxpower->setObjectName(QString::fromUtf8("totalmaxpower"));

        formLayout->setWidget(2, QFormLayout::LabelRole, totalmaxpower);

        lineTotalmaxPower = new QLineEdit(Dialog);
        lineTotalmaxPower->setObjectName(QString::fromUtf8("lineTotalmaxPower"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineTotalmaxPower);

        typeoftheaccousticsystem = new QLabel(Dialog);
        typeoftheaccousticsystem->setObjectName(QString::fromUtf8("typeoftheaccousticsystem"));

        formLayout->setWidget(3, QFormLayout::LabelRole, typeoftheaccousticsystem);

        linetypeoftheAccSys = new QLineEdit(Dialog);
        linetypeoftheAccSys->setObjectName(QString::fromUtf8("linetypeoftheAccSys"));

        formLayout->setWidget(3, QFormLayout::FieldRole, linetypeoftheAccSys);

        Cost = new QLabel(Dialog);
        Cost->setObjectName(QString::fromUtf8("Cost"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Cost);

        lineCost = new QLineEdit(Dialog);
        lineCost->setObjectName(QString::fromUtf8("lineCost"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineCost);


        gridLayout->addLayout(formLayout, 0, 0, 1, 6);


        retranslateUi(Dialog);
        QObject::connect(pushButAccept, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(pushButReject, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButAccept->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
        RFspeaker->setText(QCoreApplication::translate("Dialog", "RF speakers", nullptr));
        Midrangespeaker->setText(QCoreApplication::translate("Dialog", "Midrange speakers", nullptr));
        Bassspeaker->setText(QCoreApplication::translate("Dialog", "Bass speakers", nullptr));
        Frequencyrange->setText(QCoreApplication::translate("Dialog", "Frequecy range", nullptr));
        Guarantee->setText(QCoreApplication::translate("Dialog", "Guarantee", nullptr));
        pushButReject->setText(QCoreApplication::translate("Dialog", "Cancel", nullptr));
        Country->setText(QCoreApplication::translate("Dialog", "Country", nullptr));
        Frontpower->setText(QCoreApplication::translate("Dialog", "Front power", nullptr));
        Frontmaxpower->setText(QCoreApplication::translate("Dialog", "Front max power", nullptr));
        Frontsensetivity->setText(QCoreApplication::translate("Dialog", "Front sensetivity", nullptr));
        FrontImpedance->setText(QCoreApplication::translate("Dialog", "Front Impedance", nullptr));
        Nameoftheaccousticsystem->setText(QCoreApplication::translate("Dialog", "Name of the accoustic system", nullptr));
        Totalratedpower->setText(QCoreApplication::translate("Dialog", "Total rated power", nullptr));
        totalmaxpower->setText(QCoreApplication::translate("Dialog", "Total max power", nullptr));
        typeoftheaccousticsystem->setText(QCoreApplication::translate("Dialog", "Type of the accoustic system", nullptr));
        Cost->setText(QCoreApplication::translate("Dialog", "Cost", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
