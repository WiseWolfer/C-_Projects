#ifndef SPEAKER_ENCLOSURE_HPP
#define SPEAKER_ENCLOSURE_HPP

#include <iostream>
#include <string>

using namespace std;

///
///В нем находятся основные методы и переменные по работе с моделью акустической системы
///

class speaker_enclosure
{
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

private:
    /// название аккустической системы
    std::string name;
    /// Суммарная номинальная мощность
    int Total_rated_power;
    /// Суммарная максимальная мощность
    int Total_max_power;
    /// Тип аккустической системы
    std::string passive;
 /// Переменная структуры, где хранятся размеры ВС,СЧ, НЧ.
    LSize size;
    ///Стоимость
    int cost;
    ///Диапазон частот (фронт)
    std::string frequency_range;
     ///Гарантия
    int Guarantee;
    ///Страна производитель
    std::string country;
    ///Номинальная мощность (фронт)
    int Front_Power;
    ///Максимальная мощность (фронт)
    int Front_Max_Power;
     ///Чувствительность (фронт)
    int Front_sensitivity;
      ///Импеданс (фронт)
    int Front_Impedance;

       ///методы класса
public:
///объявляем конструктор поумолчанию
    speaker_enclosure();
///объявляем конструктор с параметрами
    speaker_enclosure(string lname,
                            int lTotal_rated_power,
                            int lTotal_max_power,
                            string lpassive,
                            const LSize lsize,
                            int lcost,
                            string lfrequency_range,
                            int lGuarantee,
                            string lcountry,
                            int lFront_Power,
                            int lFront_Max_Power,
                            int lFront_sensitivity,
                            int lFront_Impedance);

///объявляем деструктор
    ~speaker_enclosure();

///Метод задания суммарной номинальной мощности
   void setTotal_rated_power(const int lTotal_rated_power);

///Метод получения суммарной номинальной мощности
   int getTotal_rated_power() const;

///Метод задания типа аккустической системы
   void setpassive(const std::string lpassive);

///Метод получения типа аккустической системы
   std::string getpassive() const;

///Метод задания суммарной максимальной мощности
   void setTotal_max_power(const int lTotal_max_power);

///Метод получения суммарной максимальной мощности
   int getTotal_max_power() const;

///Метод задания динамиков по фронту
   void setSize(const LSize lsize);

///Метод получения динамиков по фронту
   LSize getSize() const;

///Метод задания диапазона частот
   void setfrequency_range(const std::string lfrequency_range);

///Метод получения диапазона частот
   std::string getfrequency_range() const;

///Метод задания названия акустической системы
   void setname(const std::string lname);

///Метод получения названия акустической системы
   std::string getname() const;

///Метод задания стоимости
   void setcost(const int lcost);

///Метод получения стоимости
   int getcost() const;

///Метод задания гарантии
    void setGuarantee(const int  lGuarantee);

///Метод получения гарантии
    int getGuarantee() const;

///Метод задания страны производителя
    void setcountry(const std::string lcountry);

///Метод получения страны производителя
    std::string getcountry() const;

///Метод задания мощности по фронту
    void setFront_Power(const int lFront_Power);

///Метод получения мощности по фронту
    int getFront_Power() const;

///Метод задания максимальной мощности по фронту
    void setlFront_Max_Power(const int lFront_Max_Power);

///Метод получения максимальной мощности по фронту
    int getFront_Max_Power() const;

///Метод задания чувствительности по фронту
    void setFront_sensitivity(const int lFront_sensitivity);

///Метод получения чувствительности по фронту
    int getFront_sensitivity() const;

///Метод задания импеданса по фронту
    void setFront_Impedance(const int  lFront_Impedance);

///Метод получения импеданса по фронту
    int getFront_Impedance() const;
};

#endif // SPEAKER_ENCLOSURE_HPP
