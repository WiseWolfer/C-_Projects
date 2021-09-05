#ifndef LOUNDSPEAKER_ENCLOSURE_H
#define LOUNDSPEAKER_ENCLOSURE_H
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
class loundSpeaker_enclosure    //полиморфный базовый класс
{                                   //абстрактный базовый класс

public:
    struct LSize
    {
        std::string RF_speakers;  //ВЧ динамики (фронт)
        std::string Midrange_speakers; //СЧ динамики (фронт)
        std::string bass_speakers; //НЧ динамики (фронт)
    };            //инкапсуляция это свойство системы, позволяющее объединить данные и методы, работающие с ними, в классе и скрыть детали
                  //реализации от пользователя(реализация класса)

private:                    //абстракция - это способ выделить набор значимых характеристик объекта, исключая из рассмотрения незначимые.
    std::string name;   //название аккустической системы
    int Total_rated_power;  //Суммарная номинальная мощность
    int Total_max_power;    //Суммарная максимальная мощность
    std::string passive;    //Тип акустической системы
    LSize size;      //Переменная структуры, где хранятся размеры ВС,СЧ, НЧ.
    std::string frequency_range; //Диапазон частот (фронт)
    std::string colour;          //Цвет колонок
    int weight_of_frontal_speaker; //Вес фронтальной колонки

public:
     friend class speaker_enclosure_derived;    //класс дочерний получил доступ к методам класса базового и к данным private
     loundSpeaker_enclosure();
     loundSpeaker_enclosure(std::string lname,
                            int lTotal_rated_power,
                            int lTotal_max_power,
                            std::string lpassive,
                            const LSize lsize,
                            std::string lfrequency_range,
                            std::string lcolour,
                            int lweight_of_frontal_speaker);


     loundSpeaker_enclosure(const loundSpeaker_enclosure &other);   //объявляем конструктор копирования

     virtual~loundSpeaker_enclosure();

     //методы класса

        void setTotal_rated_power(const int lTotal_rated_power);
        int getTotal_rated_power() const;

        void setpassive(const std::string lpassive);
        std::string getpassive() const;

        void setTotal_max_power(const int lTotal_max_power);
        int getTotal_max_power() const;

        void setSize(const LSize lsize);
        LSize getSize() const;

        void setfrequency_range(const std::string lfrequency_range);
        std::string getfrequency_range() const;

        void setcolour(const std::string lcolour);
        std::string getcolour() const;

        void setweight_of_frontal_speaker(const int lweight_of_frontal_speaker);
        int getweight_of_frontal_speaker() const;

        void setname(const std::string lname);
        std::string getname() const;

         virtual void show() const; //полиморфное наследование
};

#endif // LOUNDSPEAKER_ENCLOSURE_H
