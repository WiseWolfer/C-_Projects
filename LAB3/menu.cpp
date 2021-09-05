#include <iostream>
#include <string>

#include "loundspeaker_enclosure.hpp"
#include "speaker_enclosure_derived.hpp"
#include "menu.hpp"
#include <fstream>
#include <vector>
#include "checklist.h"

using namespace std;


menu::menu()
{

}

menu::~menu()
{

}
void menu::open_menu(int& k, bool &check)
{
#if WINNT
system("cls");
#else
system("clear");
#endif
    menu m;
    speaker_enclosure_derived d[20];
    checklist ch;
    speaker_enclosure_derived c;
    while(true)
    {
        #if __WINNT__
            system("cls");
        #else
            system("clear");
        #endif
        cout << "\n";
        cout << " ====================== " << endl;
        cout << " |       ����:        | " << endl;
        cout << " ====================== " << endl;
        cout << "\n";
        cout<<  "1) ��������� ����" <<endl;
        cout<<  "2) ���������� ����" << endl;
        cout << "3) ������� ���������� �� �����"<< endl;
        cout <<	"4) ��������� ��������� ������ �����" << endl;
        cout <<	"5) ������������� ��������� ������ �����" << endl;
        cout << "6) ������� ��������� ������ �����" << endl;
        cout << "7) � ���������" << endl;
        cout << "8) �����"<< endl;

        char n;
        cin >> n;

        switch (n)
        {
            case 49: m.readFile(&ch,k,check); open_menu(k,check);
            case 50: break;
            case 51: ch.add(c,k); ch.showAll(check); open_menu(k,check);
            //case 52: l.Add_to_spisok(d,k,check);open_menu(k,check);
            case 53: break;
            case 54: break;
            case 55: m.about(); open_menu(k,check);
            case 56: exit(0); break;
          }
    }
    return;
}

void menu::about() const
{
    #if __WINNT__
        system("cls");
    #else
        system("clear");
    #endif
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "��������� ����������:" << "\n"
         << "C������ 2�� ����� 4 ������," << "\n"
         << "������� ������� ������������" << endl;
    cout << "----------------------------------------------"<<endl;
    system("pause");
}

void menu::readFile(checklist *ls,int &k, bool &check)
{
#if __WINNT__
    system("cls");
#else
    system("clear");
#endif
    check = true;

    for(int i=0;i<k;i++)
    {
        int counter = 0;
        speaker_enclosure_derived constructor_copy;
        string str;
        fstream in_2("spisok_derived.txt", ios_base::in);
        if(!in_2.is_open())
        {
            cerr << "Error: ���� �� ������!" << endl;
            return;
        }
        while(!in_2.eof())
        {
            for(int i=0;i<k;i++)
            {
                getline(in_2,str);
                constructor_copy.f_derived_open(constructor_copy, str);
                ls->add(constructor_copy,k);
                counter++;
                if(counter==k)
                {
                    break;
                }
            }
        }

        in_2.close();
    }
    cout<<"File is successfully read!!!"<< endl;
    system("pause");
}

//void menu::List::Add_to_spisok(speaker_enclosure_derived *m, int &k, bool& check)
//{
//    if(check != true){
//        cerr << "������: ���� �� ��� ������!" << endl;
//        return;
//    }
//    #if __WINNT__
//        system("cls");
//    #else
//        system("clear");
//    #endif
//        List s;
//        //Node nod;
//        Node *temp = new Node;
//        temp->sled = NULL;  // �� ���������� ������ ������
//        temp->pred=Head; //��������� ����� �� ���������� �������
//        temp->sled=Tail; //��������� ����� �� ��������� �������
//        Head=temp;
//        cout << "\n\n ���������� �������� \n �������:"<<endl;
//        cout << "\t �������� ������������� �������: ";cin >> temp->name; cout<<endl;
//        cout << "\t ����� ����������� ��������: ";cin >> temp->Total_rated_power; cout<<endl;
//        cout << "\t ����� ������������ ��������: ";cin >> temp->Total_max_power;cout<<endl;
//        cout << "\t ��� ������������� �������: ";cin >> temp->passive;cout<<endl;
//        cout << "\t ����������� ��: � ��, �������� ��� ��������";
//        cin  >> temp->size.RF_speakers;
//        cout << "\t ";cin >> temp->size.Midrange_speakers;
//        cout << "\t "; cin >> temp->size.bass_speakers; cout<<endl;
//        cout << "\t ���� ������������� �������:  ";cin >>temp->cost;cout<<endl;
//        cout << "\t �������� ������: ��� "; cin >> temp->frequency_range;cout<<endl;
//        cout << "\t ��������: � ������� ";cin >>temp->Guarantee; cout<<endl;
//        cout << "\t ������ �������������: ";cin >> temp->country;cout<<endl;
//        cout << "\t ����������� �������� (�����) ��: ";cin >> temp->Front_Power;cout<<endl;
//        cout << "\t ������������ �������� (�����) ��: "; cin >>temp->Front_Max_Power;cout<<endl;
//        cout << "\t ���������������� (�����) � ���: " ; cin >> temp->Front_sensitivity;cout<<endl;
//        cout << "\t �������� (�����) � ��: "; cin >> temp->Front_Impedance;cout<<endl;

//if(Tail != NULL) //���� � ������ ���-�� �����
//{
//    temp->pred=Tail; //��������� ����� �� ���������� ������� � �����. ����
//    Head->sled=temp; //��������� ����� ���������� �� ������� ��������
//    Head=temp; //������ ����� ������
//}
// else{
//        temp->pred =NULL;
//        Head=Tail=temp;
//     }
//    //m[k++];
//    k++;
//    cout << k << endl;
//    cout << "������ ���������! " << endl;

//    system("pause");
//}



