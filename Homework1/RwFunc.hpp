#ifndef READFUNC_HPP
#define READFUNC_HPP

#include <string>

using namespace std;

struct Petrol
{
    int nomer;  //����� ������
    string fio; //��� ���������� �����
    string data;    //���� ����� ��������
    string benzin_marks;    //����� �������
    int volume;     //����� ���������� �������
    float income;   //������� �� ����� � ���. � ���.
};

void convertSTR(string, struct Petrol &);
void Read_File_1(Petrol*,int&,bool&);
void F_Write(Petrol*,int &);
void F_Delete(Petrol*,int &,bool &);
void F_Add(Petrol*,int &,bool &);

#endif // READFUNC_HPP

