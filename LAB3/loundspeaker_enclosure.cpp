#include "loundspeaker_enclosure.hpp"
#include "menu.hpp"
#include <fstream>
#include <iostream>
#include "speaker_enclosure_derived.hpp"
#include <string>
#include <vector>

using namespace std;

loundSpeaker_enclosure::loundSpeaker_enclosure():   //конструктор поумолчанию
      name("")
    , Total_rated_power(0)
    , Total_max_power(0)
    , passive("")
    , size({"","", ""})
    ,cost(0)
    , frequency_range("")
{

}

loundSpeaker_enclosure::loundSpeaker_enclosure(std::string lname,            //конструктор с парметрами
                                                 int lTotal_rated_power,
                                                 int lTotal_max_power,
                                                 std::string lpassive,
                                                 const LSize lsize,
                                                 int lcost,
                                                 std::string lfrequency_range):
     name(lname)
    ,Total_rated_power(lTotal_rated_power)
    ,Total_max_power(lTotal_max_power)
    ,passive(lpassive)
    ,size(lsize)
    ,cost(lcost)
    ,frequency_range(lfrequency_range)
{


}

loundSpeaker_enclosure::loundSpeaker_enclosure(const loundSpeaker_enclosure &other):    //конструктор копирования
name(other.name)
,Total_rated_power(other.Total_rated_power)
,Total_max_power(other.Total_max_power)
,passive(other.passive)
,size(other.size)
,frequency_range(other.frequency_range)
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

void loundSpeaker_enclosure::setname(const string lname)
{
    name = lname;
}

string loundSpeaker_enclosure::getname() const
{
    return name;
}

void loundSpeaker_enclosure::setcost(const int lcost)
{
    cost = lcost;
}

int loundSpeaker_enclosure::getcost() const
{
    return cost;
}

void loundSpeaker_enclosure::f_open(loundSpeaker_enclosure &l, const string& str)
{
      int indexNow=0;
      int indexLast = 0;
      vector<string> result_strochka;
      vector<int> result_chislo;
      vector<int> sravnenie = {2, 3, 8};
      int length = sravnenie.size();
      for(int j=0; j<9; j++)
      {
          int convert = 0;
          string vvod = "";
          indexNow = str.find(';',indexLast); // поиск знака ";"
          for(int i = indexLast; i < indexNow; i++)
           {
                vvod+=str[i];
           }
           result_strochka.push_back(vvod);
           for(int z=0; z<length; z++)
           {
               if( j+1 == sravnenie[z])
                {
                    convert = stoi(vvod);
                    result_chislo.push_back(convert);
                    break;
                }
            }
            indexLast = indexNow + 1;
            indexNow = str.find(';',indexLast);
         }


      loundSpeaker_enclosure Sp(result_strochka[0],result_chislo[0],result_chislo[1],result_strochka[3],
      {result_strochka[4],result_strochka[5],result_strochka[6]},result_chislo[2],result_strochka[8]);
      l = Sp;

}


void loundSpeaker_enclosure::show_puk(loundSpeaker_enclosure *p, const int &k)
{
#if WINNT
system("cls");
#else
system("clear");
#endif
    for(int i=0; i<k; i++)
    {
#if WINNT
system("cls");
#else
system("clear");
#endif
        cout << "Аккустическая система под номером: " << i+1 << ":" << endl;
        cout <<"1) Название аккустической системы: " <<p[i].name<< "\n"
             << "2) Общая номинальная мощность: " << p[i].Total_rated_power <<" Вт "<< "\n"
             <<"3) Общая максимальная мощность: "<<p[i].Total_max_power<<" Вт " <<"\n"
             << "4) Тип аккустической системы: " << p[i].passive << "\n"
             << "5) Фронтальные АС: (" << p[i].size.RF_speakers << "см "<<", "
                          << p[i].size.Midrange_speakers <<"см "<< ", "
                          << p[i].size.bass_speakers <<"см "<< ")\n"
              <<"6) Цена аккустической установки: " << p[i].cost <<" руб.""\n"
             << "7) Диапозон частот: (" << p[i].frequency_range << "КГц)\n"
             << "----------------------------------------------------------------------" << endl;
        system("pause");

    }
}

void loundSpeaker_enclosure::Massive_of_classes(loundSpeaker_enclosure *p)
{
    int counter = 0;
        loundSpeaker_enclosure constructor_copy;
        string str;
        fstream in("spisok_derived"
                   ".txt", ios_base::in);
        if(!in.is_open())
        {
            cerr << "Error: Файл не открыт!" << endl;
            return;
        }
        while(!in.eof())
        {
            str="";
            getline(in,str);
            constructor_copy.f_open(constructor_copy, str);
            p[counter] = constructor_copy;
            counter++;
        }
        in.close();
}

void loundSpeaker_enclosure::show() const
{
    cout <<"1) Название аккустической системы: " <<name<< "\n"
         << "2) Общая номинальная мощность: " << Total_rated_power <<" Вт "<< "\n"
         <<"3) Общая максимальная мощность: "<<Total_max_power<<" Вт " <<"\n"
         << "4) Тип аккустической системы: " << passive << "\n"
         << "5) Фронтальные АС: (" << size.RF_speakers << "см "<<", "
                      << size.Midrange_speakers <<"см "<< ", "
                      << size.bass_speakers <<"см "<< ")\n"
          <<"6) Цена аккустической установки: " << cost <<" руб.""\n"
         << "7) Диапозон частот: (" << frequency_range << "КГц)" << endl;
    system("pause");
}

