#include "dialog.hpp"
#include "ui_dialog.h"
#include <iostream>
#include <string>
#include "QString"
#include "mainwindow.hpp"

///
/// Реализация класса диалогового окна
///

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setTotal_rated_power(const int lTotal_rated_power)
{
    ui->lineEditTotalratedpower->setText(QString::fromStdString(to_string(lTotal_rated_power)));
}

int Dialog::getTotal_rated_power() const
{
    return ui->lineEditTotalratedpower->text().toInt();
}

void Dialog::setpassive(const std::string lpassive)
{
    ui->linetypeoftheAccSys->setText(QString::fromStdString(lpassive));
}

string Dialog::getpassive() const
{
     return ui->linetypeoftheAccSys->text().toStdString();
}

void Dialog::setTotal_max_power(const int lTotal_max_power)
{
    ui->lineTotalmaxPower->setText(QString::fromStdString(to_string(lTotal_max_power)));
}

int Dialog::getTotal_max_power() const
{
    return ui->lineTotalmaxPower->text().toInt();
}

void Dialog::setSize(const Dialog::LSize lsize)
{
   ui->lineRFspeaker->setText(QString::fromStdString(lsize.RF_speakers));
   ui->lineMidrangespeaker->setText(QString::fromStdString(lsize.Midrange_speakers));
   ui->lineEditBassspeaker->setText(QString::fromStdString(lsize.bass_speakers));
}

Dialog::LSize Dialog::getSize() const
{
    Dialog::LSize lsize =
    {
        ui->lineRFspeaker->text().toStdString(),
        ui->lineMidrangespeaker->text().toStdString(),
        ui->lineEditBassspeaker->text().toStdString()
    };
    return lsize;
}

void Dialog::setfrequency_range(const std::string lfrequency_range)
{
    ui->linefrequencyrane->setText(QString::fromStdString(lfrequency_range));
}

string Dialog::getfrequency_range() const
{
    return  ui->linefrequencyrane->text().toStdString();
}


void Dialog::setname(const std::string lname)
{
    ui->lineNameACSYS->setText(QString::fromStdString(lname));
}

string Dialog::getname() const
{
    return ui->lineNameACSYS->text().toStdString();
}

void Dialog::setcost(const int lcost)
{
    ui->lineCost->setText(QString::fromStdString(to_string(lcost)));
}

int Dialog::getcost() const
{
   return  ui->lineCost->text().toInt();
}

void Dialog::setGuarantee(const int lGuarantee)
{
    ui->spinBxGuarantee->setValue(lGuarantee);
}

int Dialog::getGuarantee() const
{
    return ui->spinBxGuarantee->value();
}

void Dialog::setcountry(const std::string lcountry)
{
    ui->lineCountry->setText(QString::fromStdString(lcountry));
}

string Dialog::getcountry() const
{
    return ui->lineCountry->text().toStdString();
}

void Dialog::setFront_Power(const int lFront_Power)
{
    ui->spinBxFrontPower->setValue(lFront_Power);
}

int Dialog::getFront_Power() const
{
    return ui->spinBxFrontPower->value();
}

void Dialog::setFront_Max_Power(const int lFront_Max_Power)
{
    ui->lineFrontMaxPower->setText(QString::fromStdString(to_string(lFront_Max_Power)));
}


int Dialog::getFront_Max_Power() const
{
    return ui->lineFrontMaxPower->text().toInt();
}

void Dialog::setFront_sensitivity(const int lFront_sensitivity)
{
    return ui->spinBxFrontsensetivity->setValue(lFront_sensitivity);
}

int Dialog::getFront_sensitivity() const
{
    return ui->spinBxFrontsensetivity->value();
}

void Dialog::setFront_Impedance(const int lFront_Impedance)
{
    ui->spinBxFrontImpedance->setValue(lFront_Impedance);
}

int Dialog::getFront_Impedance() const
{
    return ui->spinBxFrontsensetivity->value();
}




