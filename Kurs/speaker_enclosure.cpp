#include "speaker_enclosure.hpp"

///
/// Реализация класса модели аккустической системы
///

speaker_enclosure::speaker_enclosure():
    name("")
   ,Total_rated_power(0)
   ,Total_max_power(0)
   ,passive("")
   ,size({"","",""})
   ,cost(0)
   ,frequency_range("")
   ,Guarantee(0)
   ,country("")
   ,Front_Power(0)
   ,Front_Max_Power(0)
   ,Front_sensitivity(0)
   ,Front_Impedance(0)
{

}

speaker_enclosure::speaker_enclosure(string lname,
                                     int lTotal_rated_power,
                                     int lTotal_max_power,
                                     string lpassive,
                                     const speaker_enclosure::LSize lsize,
                                     int lcost,
                                     string lfrequency_range,
                                     int lGuarantee,
                                     string lcountry,
                                     int lFront_Power,
                                     int lFront_Max_Power,
                                     int lFront_sensitivity,
                                     int lFront_Impedance):
    name(lname)
   ,Total_rated_power(lTotal_rated_power)
   ,Total_max_power(lTotal_max_power)
   ,passive(lpassive)
   ,size(lsize)
   ,cost(lcost)
   ,frequency_range(lfrequency_range)
   ,Guarantee(lGuarantee)
   ,country(lcountry)
   ,Front_Power(lFront_Power)
   ,Front_Max_Power(lFront_Max_Power)
   ,Front_sensitivity(lFront_sensitivity)
   ,Front_Impedance(lFront_Impedance)
{

}

speaker_enclosure::~speaker_enclosure()
{

}

void speaker_enclosure::setTotal_rated_power(const int lTotal_rated_power)
{
    Total_rated_power = lTotal_rated_power;
}

int speaker_enclosure::getTotal_rated_power() const
{
    return Total_rated_power;
}

void speaker_enclosure::setpassive(const string lpassive)
{
    passive = lpassive;
}

string speaker_enclosure::getpassive() const
{
    return passive;
}

void speaker_enclosure::setTotal_max_power(const int lTotal_max_power)
{
    Total_max_power = lTotal_max_power;
}

int speaker_enclosure::getTotal_max_power() const
{
    return Total_max_power;
}

void speaker_enclosure::setSize(const speaker_enclosure::LSize lsize)
{
    size = lsize;
}

speaker_enclosure::LSize speaker_enclosure::getSize() const
{
    return size;
}

void speaker_enclosure::setfrequency_range(const string lfrequency_range)
{
    frequency_range = lfrequency_range;
}

string speaker_enclosure::getfrequency_range() const
{
    return frequency_range;
}

void speaker_enclosure::setname(const string lname)
{
    name = lname;
}

string speaker_enclosure::getname() const
{
    return name;
}

void speaker_enclosure::setcost(const int lcost)
{
    cost = lcost;
}

int speaker_enclosure::getcost() const
{
    return cost;
}

void speaker_enclosure::setGuarantee(const int lGuarantee)
{
    Guarantee = lGuarantee;
}

int speaker_enclosure::getGuarantee() const
{
    return Guarantee;
}

void speaker_enclosure::setcountry(const string lcountry)
{
    country = lcountry;
}

string speaker_enclosure::getcountry() const
{
    return country;
}

void speaker_enclosure::setFront_Power(const int lFront_Power)
{
    Front_Power =lFront_Power;
}

int speaker_enclosure::getFront_Power() const
{
    return Front_Power;
}

void speaker_enclosure::setlFront_Max_Power(const int lFront_Max_Power)
{
    Front_Max_Power = lFront_Max_Power;
}

int speaker_enclosure::getFront_Max_Power() const
{
    return Front_Max_Power;
}

void speaker_enclosure::setFront_sensitivity(const int lFront_sensitivity)
{
    Front_sensitivity = lFront_sensitivity;
}

int speaker_enclosure::getFront_sensitivity() const
{
    return Front_sensitivity;
}

void speaker_enclosure::setFront_Impedance(const int lFront_Impedance)
{
    Front_Impedance = lFront_Impedance;
}

int speaker_enclosure::getFront_Impedance() const
{
    return Front_Impedance;
}
