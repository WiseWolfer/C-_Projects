#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
#include "RwFunc.hpp"
#include <windows.h>
#include <clocale>
#include <cstdlib>

using namespace std;


void Read_File_1(Petrol* gaz,int &NC,bool &Open)
{
    fstream in("spisok.txt", ios_base::in); //��������� �������� ����� ��� �����

    if(!in.is_open())
    {
        cerr << "������: ���� �� ������!"<< endl;
        return;

    }
    if(Open){
        cerr <<"������: ���� ��� ������!"<< endl;
        return;
    }

    string str;
    NC=0;

    while(!in.eof())
    {
        getline(in, str);
        if(str.empty())continue;
        Petrol gazik;
        convertSTR(str,gazik);
        gaz[NC] = gazik;
        NC++;
    }

    Open=true;

    in.close();

    #if __WINNT__   //������ ������� ������ ��� windows
        system("cls");
    #else               // ��� ������ ������ �������(linux,mac os � ��.)
        system("clear");
    #endif

    cout<<"\n\n���� ������� ��������!\n"<< endl;

}
void convertSTR(string str, struct Petrol &gazik)
{
    int indexNow,indexLast = 0;

    string t1,t2,t3,t4,t5,t6;

    indexNow = str.find(';',indexLast); //���������� � indexNow (����� ������� ;)

    for(int i = indexLast; i < indexNow; i++)
        t1+=str[i];             //���������� ����� � t1

     gazik.nomer = stoi(t1);    //������������ � �����
     indexLast = indexNow + 1;          //������ �� ���� ������ ����� ; � ���������� � indexLast �����
     indexNow = str.find(';',indexLast);

    for(int i = indexLast; i < indexNow; i++)
        t2+=str[i];

    gazik.fio = t2;
    indexLast = indexNow + 1;
    indexNow = str.find(';',indexLast);

    for(int i = indexLast; i < indexNow; i++)
        t3+=str[i];

    gazik.data = t3;
    indexLast = indexNow + 1;
    indexNow = str.find(';',indexLast);

    for(int i = indexLast; i < indexNow; i++)
        t4+=str[i];

    gazik.benzin_marks = t4;
    indexLast = indexNow + 1;
    indexNow = str.find(';',indexLast);

     for(int i = indexLast; i < indexNow; i++)
         t5+=str[i];

     gazik.volume = stoi(t5);
     indexLast = indexNow + 1;
     indexNow = str.find(';',indexLast);

      for(int i = indexLast; i < indexNow; i++)
          t6+=str[i];
      gazik.income = stof(t6);
}

void F_Write(Petrol* gaz,int &NC){  //�������� ����

    fstream out("spisok.txt", ios_base::out);   //��������� �������� ����� ��� ������
    if(!out.is_open())
    {
         cerr << "Error: ���� �� ������!" << endl;
         return;
    }
    for(int i = 0; i < NC;i++)
    {
       out << gaz[i].nomer<<";"<<gaz[i].fio<<";"
            <<gaz[i].data<<";"<< gaz[i].benzin_marks<<";"
            <<gaz[i].volume<<";"<<gaz[i].income<<";"<<endl;
    }
    out.close();
    #if __WINNT__
        system("cls");
    #else
        system("clear");
    #endif
    cout << "\n\n ���� ��� ������� \n" <<endl;
}

void F_Add(Petrol* gaz,int &NC,bool &Open)    //�������� ����� ������ � ����������� ������
{
    if(!Open){
        cerr << "������: ���� �� ��� ������!" << endl;
        return;
    }
    #if __WINNT__
        system("cls");
    #else
        system("clear");
    #endif
    Petrol gazik;
    cout << "\n\n ���������� �������� \n �������:"<<endl;
    cout  <<"\t����� ������: ";cin >> gazik.nomer;
    cout  <<"\t���: ";_flushall();getline(cin , gazik.fio);
    cout  <<"\t���� ���������: "; _flushall();getline(cin , gazik.data);
    cout  <<"\t�����_�������: ";_flushall();getline(cin , gazik.benzin_marks);  //flushall:�������� � ������ c���������� ���� �������� �������,
    cout  <<"\t����� ���������� ������� �� �����: ";cin >> gazik.volume;    // ��������� � �������� ������, � ����� � � ������� ���� ������� �������.
    cout  <<"\t������� �� �����: ";cin >> gazik.income;
    gaz[NC] = gazik;
    NC++;
}
void F_Delete(Petrol* gaz,int &NC,bool &Open) //�������� �� �������
{
    if(!Open){
        cerr << "������:  ���� �� ������!" << endl;
        return;
    }

    #if __WINNT__
    system("cls");
    #else
    system("clear");
    #endif
    bool found = false;
    int DelNom = -1;
    cout << "\n\n �������� �������� \n ������� ID ���������� ��������:";
    cin >> DelNom;
    for(int i = 0; i < NC; i++)
    {
        if(gaz[i].nomer == DelNom)  //���������� ���������� ����� ������ �� 10 ��� ��������
        {
            found =true;
            break;
        }
        else
           continue;    //������� �� ����. �������� �����, ��������� ������ ���������� ��������
    }

    //if(DelNom <= 10 && DelNom > 0)
    if(found)
    {
        for(int i = DelNom - 1;i < NC - 1;i++ ) //����� �������� ������ ���������� (1-10)
        {
            gaz[i] = gaz[i+1];                  //���� �� ���������� � ��������
        }
        NC--;
        cout << "\n ������� ������ \n"<<endl;
    }
    else{
        cout << "\n ������� � �������� ID �� ������\n"<<endl;
    }
}
