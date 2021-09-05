#include "speaker_enclosure_derived.hpp"
#include "loundspeaker_enclosure.hpp"
#include "menu.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


speaker_enclosure_derived::speaker_enclosure_derived():    //����������� �����������
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
                                                     int lcost,
                                                     std::string lfrequency_range,
                                                     int lGuarantee,
                                                     std::string lcountry,  //����������� � �����������
                                                     int lFront_Power,
                                                     int lFront_Max_Power,
                                                     int lFront_sensitivity,
                                                     int lFront_Impedance):
    loundSpeaker_enclosure(lname
                           ,lTotal_rated_power
                           ,lTotal_max_power
                           ,lpassive
                           ,lsize
                           ,lcost
                           ,lfrequency_range)
    ,Guarantee(lGuarantee)
    ,country(lcountry)
    ,Front_Power(lFront_Power)
    ,Front_Max_Power(lFront_Max_Power)
    ,Front_sensitivity(lFront_sensitivity)
    ,Front_Impedance(lFront_Impedance)
{

}


speaker_enclosure_derived::~speaker_enclosure_derived() //����������
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

void speaker_enclosure_derived::f_derived_open(speaker_enclosure_derived &k, const string& str)
{

    int indexNow = 0;
    int indexLast = 0;

    vector<string> result_strochka;
    vector<int> result_chislo;
    vector<int> sravnenie = {2, 3, 8, 10, 12, 13, 14, 15};
    int length = sravnenie.size();
    for(int j=0; j<15; j++)
    {
        int convert = 0;
        string vvod = "";
        indexNow = str.find(';',indexLast);
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

   speaker_enclosure_derived Speaker2(result_strochka[0],result_chislo[0],result_chislo[1],result_strochka[3],
   {result_strochka[4],result_strochka[5],result_strochka[6]},result_chislo[2],result_strochka[8],result_chislo[3],
           result_strochka[10],result_chislo[4],result_chislo[5],result_chislo[6],result_chislo[7]);

   k = Speaker2;
   return;

}

void speaker_enclosure_derived::show_derived(speaker_enclosure_derived *n, const int &k)
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
        cout << "������������� ������� ��� �������: " << i+1 << ":" << endl;
        cout << "8) ��������: " <<n[i].Guarantee<< " �������" << "\n"
             << "9) ������ �������������: " << n[i].country << "\n"
             << "10) ����������� �������� (�����): "<<n[i].Front_Power <<" �� " <<"\n"
             << "11) ������������ �������� (�����): " << n[i].Front_Max_Power << " �� " <<"\n"
             << "12) �������� ������ (�����): " << n[i].Front_sensitivity << " ��� \n"
             << "13) �������� (�����): " << n[i].Front_Impedance<< " �� \n"<<
                 "-----------------------------------------------------------" << endl;
        system("pause");

    }
}

void speaker_enclosure_derived::show() const            //����� show() ��� ��������� ������
{
    cout << "8) ��������: " <<Guarantee<< " �������" << "\n"
         << "9) ������ �������������: " << country << "\n"
         << "10) ����������� �������� (�����): "<<Front_Power<<" �� " <<"\n"
         << "11) ������������ �������� (�����): " << Front_Max_Power << " �� " <<"\n"
         << "12) �������� ������ (�����): " << Front_sensitivity<< " ��� \n"
         << "13) �������� (�����): " << Front_Impedance << " �� " << endl;
    system("pause");
}



ostream& operator<<(ostream& os, const speaker_enclosure_derived* n)    //���������� �������� ��������� � �����
{
    for(int i =0; i< 15; i++)
    {
        #if WINNT
        system("cls");
        #else
        system("clear");
        #endif
        os <<"����������: "<<"\n"<<"------------------------------------------------------------------\n";
        os <<"������������� ������� �����: "<< i+1 <<"\n";
             os<<"1) �������� ������������� �������: "<<n[i].getname()<< endl;
             os<< "2) ����� ����������� ��������: " <<n[i].getTotal_rated_power()<<" �� "<< endl;
             os<<"3) ����� ������������ ��������: "<<n[i].getTotal_max_power()<<" �� " <<endl;
             os<< "4) ��� ������������� �������: " << n[i].getpassive() << endl;
             os<< "5) ����������� ��: ("<< n[i].getSize().RF_speakers <<"��, "<<n[i].getSize().Midrange_speakers<<
                  "��, "<<n[i].getSize().bass_speakers<<"�� )"<<endl;
             os << "6) ���� ������������� �������: " << n[i].getcost()<<" ���." << endl;
             os<< "7) �������� ������: (" << n[i].getfrequency_range() << "���)"<<endl;
             os << "8) ��������: " <<n[i].getGuarantee()<<" ������� " << endl;        //�����������
             os << "9) ������ �������������: " << n[i].getcountry() << endl;
             os << "10) ����������� �������� (�����): "<<n[i].getFront_Power()<<" �� " <<endl;
             os << "11) ������������ �������� (�����): " << n[i].getFront_Max_Power()<< " �� " <<endl;
             os << "12) ���������������� (�����): " << n[i].getFront_sensitivity()<< "  ��� "<<endl;
             os << "13) �������� (�����): " << n[i].getFront_Impedance() << " �� " << endl;
             os <<"------------------------------------------------------------------\n";
             system("pause");
      }
      return os;
}





