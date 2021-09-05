#include "speaker_enclosure_derived.hpp"
#include "loundspeaker_enclosure.hpp"

speaker_enclosure_derived::speaker_enclosure_derived():    //конструктор поумолчанию
    loundSpeaker_enclosure()
    ,Guarantee(0)
    ,country("")
    ,Front_Power(0)
    ,Front_Max_Power(0)
    ,Front_sensitivity(0)
    ,Front_Impedance(0)
{

}

speaker_enclosure_derived::speaker_enclosure_derived(std::string lname,
                                                     int lTotal_rated_power,
                                                     int lTotal_max_power,
                                                     std::string lpassive,
                                                     const LSize lsize,
                                                     std::string lfrequency_range,
                                                     std::string lcolour,
                                                     int lweight_of_frontal_speaker,
                                                     int lGuarantee,
                                                     std::string lcountry,  //конструктор с параметрами
                                                     int lFront_Power,
                                                     int lFront_Max_Power,
                                                     int lFront_sensitivity,
                                                     int lFront_Impedance):
    loundSpeaker_enclosure(lname
                           ,lTotal_rated_power
                           ,lTotal_max_power
                           ,lpassive
                           ,lsize
                           ,lfrequency_range
                           ,lcolour
                           ,lweight_of_frontal_speaker)
    ,Guarantee(lGuarantee)
    ,country(lcountry)
    ,Front_Power(lFront_Power)
    ,Front_Max_Power(lFront_Max_Power)
    ,Front_sensitivity(lFront_sensitivity)
    ,Front_Impedance(lFront_Impedance)
{

}


speaker_enclosure_derived::~speaker_enclosure_derived() //деструктор
{

}


void speaker_enclosure_derived::setGuarantee(const int lGuarantee)
{
    Guarantee =lGuarantee;
}

int speaker_enclosure_derived::getGuarantee() const
{
    return Guarantee;
}

void speaker_enclosure_derived::setcountry(const std::string lcountry)
{
        country = lcountry;
}

std::string speaker_enclosure_derived::getcountry() const
{
    return country;
}

void speaker_enclosure_derived::setFront_Power(const int lFront_Power)
{
    Front_Power=lFront_Power;
}

int speaker_enclosure_derived::getFront_Power() const
{
    return Front_Power;
}

void speaker_enclosure_derived::setlFront_Max_Power(const int lFront_Max_Power)
{
    Front_Max_Power=lFront_Max_Power;
}

int speaker_enclosure_derived::getFront_Max_Power() const
{
    return Front_Max_Power;
}

void speaker_enclosure_derived::setFront_sensitivity(const int lFront_sensitivity)
{
    Front_sensitivity=lFront_sensitivity;
}

int speaker_enclosure_derived::getFront_sensitivity() const
{
    return Front_sensitivity;
}

void speaker_enclosure_derived::setFront_Impedance(const int lFront_Impedance)
{
    Front_Impedance =lFront_Impedance;
}

int speaker_enclosure_derived::getFront_Impedance() const
{
    return Front_Impedance;
}

void speaker_enclosure_derived::show() const            //Метод show() для дочернего класса
{
    cout <<"9) Гарантия: " <<Guarantee<< "\n"
         << "10) Страна производитель: " << country << "\n"
         <<"11) Номинальная мощность (фронт): "<<Front_Power<<" Вт " <<"\n"
         << "12) Максимальная мощность (фронт): " << Front_Max_Power << " Вт " <<"\n"
         << "13) Диапазон частот (фронт): " << Front_sensitivity<< " КГц \n"
         << "14) Импеданс (фронт): " << Front_Impedance << " Ом " << endl;
}
/*
    void operator<<(ostream& os, const speaker_enclosure_derived& Speaker)
    {
             os<<"1) Название аккустической системы: "<<Speaker.getname();
             os<< "2) Общая номинальная мощность: " <<Speaker.getTotal_rated_power();
             os<<"3) Общая максимальная мощность: "<<Speaker.getTotal_max_power();
             os<< "4) Тип аккустической системы: " << Speaker.getpassive();
             os<< "5) Фронтальные АС: "<< Speaker.getSize().RF_speakers<<Speaker.getSize().Midrange_speakers
                  <<Speaker.getSize().bass_speakers;
             os<< "6) Диапозон частот: " << Speaker.getfrequency_range();
             os << "7) Цвет: " << Speaker.getcolour();
             os<< "8) Вес фронтальной колонки: " << Speaker.getweight_of_frontal_speaker();
             os << "9) Гарантия: " <<Speaker.getGuarantee()<<" месяцев ";
             os << "10) Страна производитель: " << Speaker.getcountry();
             os << "11) Номинальная мощность (фронт): "<<Speaker.getFront_Power();
             os << "12) Максимальная мощность (фронт): " << Speaker.getFront_Max_Power();
             os << "13) Чувствительность (фронт): " << Speaker.getFront_sensitivity();
             os << "14) Импеданс (фронт): " << Speaker.getFront_Impedance();
    }
*/
ostream& operator<<(ostream& os, const speaker_enclosure_derived& Speaker)    //перегрузка операции поместить в поток
{
             os<<"1) Название аккустической системы: "<<Speaker.getname()<< endl;
             os<< "2) Общая номинальная мощность: " <<Speaker.getTotal_rated_power()<<" Вт "<< endl;
             os<<"3) Общая максимальная мощность: "<<Speaker.getTotal_max_power()<<" Вт " <<endl;
             os<< "4) Тип аккустической системы: " << Speaker.getpassive() << endl;
             os<< "5) Фронтальные АС: ("<< Speaker.getSize().RF_speakers <<"см, "<<Speaker.getSize().Midrange_speakers<<
                  "см, "<<Speaker.getSize().bass_speakers<<"см )"<<endl;
             os<< "6) Диапозон частот: " << Speaker.getfrequency_range() << " КГц"<<endl;
             os << "7) Цвет: " << Speaker.getcolour() << endl;
             os<< "8) Вес фронтальной колонки: " << Speaker.getweight_of_frontal_speaker()<<" кг " << endl;
             os << "9) Гарантия: " <<Speaker.getGuarantee()<<" месяцев " << endl;        //полиморфизм
             os << "10) Страна производитель: " << Speaker.getcountry() << endl;
             os << "11) Номинальная мощность (фронт): "<<Speaker.getFront_Power()<<" Вт " <<endl;
             os << "12) Максимальная мощность (фронт): " << Speaker.getFront_Max_Power()<< " Вт " <<endl;
             os << "13) Чувствительность (фронт): " << Speaker.getFront_sensitivity()<< " Ом "<<endl;
             os << "14) Импеданс (фронт): " << Speaker.getFront_Impedance() << " Ом " << endl;
    return os;
}





