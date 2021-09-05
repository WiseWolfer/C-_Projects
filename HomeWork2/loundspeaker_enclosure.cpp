#include "loundspeaker_enclosure.hpp"

#include <iostream>

using namespace std;

loundSpeaker_enclosure::loundSpeaker_enclosure():   //����������� �����������
      name("")
    , Total_rated_power(0)
    , Total_max_power(0)
    , passive("")
    , size({"","", ""})
    , frequency_range("")
    , colour("")
    , weight_of_frontal_speaker(0)

{

}

loundSpeaker_enclosure::loundSpeaker_enclosure(std::string lname,            //����������� � ����������
                                                 int lTotal_rated_power,
                                                 int lTotal_max_power,
                                                 std::string lpassive,
                                                 const LSize lsize,
                                                 std::string lfrequency_range,
                                                 std::string lcolour,
                                                 int lweight_of_frontal_speaker):
     name(lname)
    ,Total_rated_power(lTotal_rated_power)
    ,Total_max_power(lTotal_max_power)
    ,passive(lpassive)
    ,size(lsize)
    ,frequency_range(lfrequency_range)
    ,colour(lcolour)
    ,weight_of_frontal_speaker(lweight_of_frontal_speaker)
{


}

loundSpeaker_enclosure::loundSpeaker_enclosure(const loundSpeaker_enclosure &other):    //����������� �����������
name(other.name)
,Total_rated_power(other.Total_rated_power)
,Total_max_power(other.Total_max_power)
,passive(other.passive)
,size(other.size)
,frequency_range(other.frequency_range)
,colour(other.colour)
,weight_of_frontal_speaker(other.weight_of_frontal_speaker)
{


}


loundSpeaker_enclosure::~loundSpeaker_enclosure()
{

}

void loundSpeaker_enclosure::setTotal_rated_power(const int lTotal_rated_power)
{
    Total_rated_power=lTotal_rated_power;
}

int loundSpeaker_enclosure::getTotal_rated_power() const
{
    return Total_rated_power;
}

void loundSpeaker_enclosure::setpassive(const std::string lpassive)
{
    passive = lpassive;
}

std::string loundSpeaker_enclosure::getpassive() const
{
    return passive;
}

void loundSpeaker_enclosure::setTotal_max_power(const int lTotal_max_power)
{
    Total_max_power= lTotal_max_power;
}

int loundSpeaker_enclosure::getTotal_max_power() const
{
    return Total_max_power;
}

void loundSpeaker_enclosure::setSize(const loundSpeaker_enclosure::LSize lsize)
{
    size = lsize;
}

loundSpeaker_enclosure::LSize loundSpeaker_enclosure::getSize() const
{
    return size;
}

void loundSpeaker_enclosure::setfrequency_range(const std::string lfrequency_range)
{
    frequency_range=lfrequency_range;
}

std::string loundSpeaker_enclosure::getfrequency_range() const
{
    return frequency_range;
}

void loundSpeaker_enclosure::setcolour(const std::string lcolour)
{
    colour=lcolour;
}

std::string loundSpeaker_enclosure::getcolour() const
{
    return colour;
}

void loundSpeaker_enclosure::setweight_of_frontal_speaker(const int lweight_of_frontal_speaker)
{
    weight_of_frontal_speaker=lweight_of_frontal_speaker;
}

int loundSpeaker_enclosure::getweight_of_frontal_speaker() const
{
    return weight_of_frontal_speaker;
}

void loundSpeaker_enclosure::setname(const string lname)
{
    name = lname;
}

string loundSpeaker_enclosure::getname() const
{
    return name;
}

void loundSpeaker_enclosure::show() const
{
    cout <<"1) �������� ������������� �������: " <<name<< "\n"
         << "2) ����� ����������� ��������: " << Total_rated_power <<" �� "<< "\n"
         <<"3) ����� ������������ ��������: "<<Total_max_power<<" �� " <<"\n"
         << "4) ��� ������������� �������: " << passive << "\n"
         << "5) ����������� ��: (" << size.RF_speakers << "�� "<<", "
                      << size.Midrange_speakers <<"�� "<< ", "
                      << size.bass_speakers <<"�� "<< ")\n"
         << "6) �������� ������: " << frequency_range << " ���"<<"\n"
         << "7) ����: " << colour << "\n"
         << "8) ��� ����������� �������: " << weight_of_frontal_speaker<<" �� " << endl;
}

