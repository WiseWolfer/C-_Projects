#include "checklist.h"
#include <fstream>
#include <iostream>
#include "menu.hpp"
using namespace std;

checklist::checklist()
{

}

checklist::~checklist()
{
    while (first) //���� �� ������ �� ������ ������ ���-�� ����
     {
         last = first->next; //��������� ����� ������ ���������� ����� ������
         delete first; //������� ������ �� ������� �����
         first = last; //����� ������ ������ �� ����� ���������� ��������
     }
}

void checklist::add(speaker_enclosure_derived p,int &k)
{
    #if __WINNT__
        system("cls");
    #else
        system("clear");
    #endif
           menu s;
           string str;


                Data *temp = new Data;
                temp->next = NULL;
                temp->sp = p;
                if(first!= 0)
                {
                  temp->priv = last;
                  last->next = temp;
                  last = temp;
                 }
                 else
                 {
                   temp->priv = NULL;
                   first = temp;
                   last = first;
                  }


}
void checklist::showAll(bool &check) //�������� �������� �� �����
{
#if WINNT
    system("cls");
#else
    system("clear");
#endif

    Data *pointer = first;

    if(check == true)
    {
        while(pointer!=NULL)
        {

            cout << pointer->sp.getname() << " "<<pointer->sp.getTotal_max_power()<<" "<<
                pointer->sp.getTotal_rated_power()<<" "<< pointer->sp.getpassive()<<" "<<
                pointer->sp.getSize().RF_speakers<<" "<<pointer->sp.getSize().Midrange_speakers<<" "<<
                pointer->sp.getSize().bass_speakers<<" "<< pointer->sp.getcost()<<" "<<
                pointer->sp.getfrequency_range()<<" "<<pointer->sp.getGuarantee()<<" "<<
                pointer->sp.getcountry()<<" "<<pointer->sp.getFront_Power()<<" "<<
                pointer->sp.getFront_Max_Power()<<" "<<pointer->sp.getFront_sensitivity()<<" "<<
                pointer->sp.getFront_Impedance() << endl;
                pointer=pointer->next;
        }
    }
    else
    {
        cout<<"File is not opened yet!!! "<< endl;
    }
    system("pause");
}
