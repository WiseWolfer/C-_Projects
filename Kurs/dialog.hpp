#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "speaker_enclosure.hpp"

///
///В нем находятся основные методы и переменные по работе с диалоговым окном
///

namespace Ui {
class Dialog;
}


class Dialog : public QDialog
{
    Q_OBJECT
///Данные классы(переменные класса)
public:

    struct LSize
    {
        ///ВЧ динамики (фронт)
        std::string RF_speakers;

        ///СЧ динамики (фронт)
        std::string Midrange_speakers;

        ///НЧ динамики (фронт)
        std::string bass_speakers;
    };

///Методы класса

    ///конструктор диалогового окна
    explicit Dialog(QWidget *parent = nullptr);

    ///деструктор диалогового окна
    ~Dialog();

 ///Метод задания суммарной номинальной мощности в диалоговое окно
    void setTotal_rated_power(const int lTotal_rated_power);

///Метод получения суммарной номинальной мощности из диалогового окна
    int getTotal_rated_power() const;

  ///Метод задания типа аккустической системы в диалоговое окно
    void setpassive(const std::string lpassive);

    ///Метод получения типа аккустической системы из диалогового окна
    std::string getpassive() const;

    ///Метод задания суммарной максимальной мощности в диалоговое окно
    void setTotal_max_power(const int lTotal_max_power);

    ///Метод получения суммарной максимальной мощности из диалогового окна
    int getTotal_max_power() const;

    ///Метод задания динамиков по фронту в диалоговое окно
    void setSize(const LSize lsize);

    ///Метод получения динамиков по фронту из диалогового окна
    LSize getSize() const;

    ///Метод задания диапазона частот в диалоговое окно
    void setfrequency_range(const std::string lfrequency_range);

    ///Метод получения диапазона частот из диалогового окна
    std::string getfrequency_range() const;

    ///Метод задания названия акустической системы в диалоговое окно
    void setname(const std::string lname);

    ///Метод получения названия акустической системы из диалогового окна
    std::string getname() const;

    ///Метод задания стоимости в диалогового окна
    void setcost(const int lcost);

    ///Метод получения стоимости из диалоговое окно
    int getcost() const;

    ///Метод задания гарантии в диалоговое окно
     void setGuarantee(const int  lGuarantee);

     ///Метод получения гарантии из диалогового окна
     int getGuarantee() const;

     ///Метод задания страны производителя   в диалоговое окно
     void setcountry(const std::string lcountry);

     ///Метод получения страны производителя из диалогового окна
     std::string getcountry() const;

     ///Метод задания мощности по фронту в диалоговое окно
     void setFront_Power(const int lFront_Power);

     ///Метод получения мощности по фронту из диалогового окна
     int getFront_Power() const;

     ///Метод задания максимальной мощности по фронту  в диалоговое окно
     void setFront_Max_Power(const int lFront_Max_Power);

     ///Метод получения максимальной мощности по фронту из диалогового окна
     int getFront_Max_Power() const;

     ///Метод задания чувствительности по фронту  в диалоговое окно
     void setFront_sensitivity(const int lFront_sensitivity);

     ///Метод получения чувствительности по фронту из диалогового окна
     int getFront_sensitivity() const;

     ///Метод задания импеданса по фронту  в диалоговое окно
     void setFront_Impedance(const int  lFront_Impedance);

     ///Метод получения импеданса по фронту из диалогового окна
     int getFront_Impedance() const;

private slots:

private:
     ///Указатель на диалоговое окно
     Ui::Dialog *ui;
};

#endif // DIALOG_H
