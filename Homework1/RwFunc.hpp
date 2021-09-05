#ifndef READFUNC_HPP
#define READFUNC_HPP

#include <string>

using namespace std;

struct Petrol
{
    int nomer;  //номер записи
    string fio; //ФИО начальника смены
    string data;    //дата смены человека
    string benzin_marks;    //марка бензина
    int volume;     //объем проданного бензина
    float income;   //выручка за смену в руб. и коп.
};

void convertSTR(string, struct Petrol &);
void Read_File_1(Petrol*,int&,bool&);
void F_Write(Petrol*,int &);
void F_Delete(Petrol*,int &,bool &);
void F_Add(Petrol*,int &,bool &);

#endif // READFUNC_HPP

