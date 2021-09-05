#include <iostream>
#include "loundspeaker_enclosure.hpp"
#include <windows.h>
#include "speaker_enclosure_derived.hpp"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    loundSpeaker_enclosure Sp("YAMAHA NS-6490",
                                        70,
                                        140,
                                        "���������",
                                        {"1 � 2.2",
                                        "1 � 10",
                                        "1 � 20"},
                                        "45 - 23",
                                        "������",
                                        6);

    speaker_enclosure_derived Speaker2("YAMAHA NS-6490",
                                             70,
                                             140,
                                             "���������",
                                             {"1 � 2.2",
                                             "1 � 10",
                                             "1 � 20"},
                                             "45 - 23",
                                             "������",
                                               6,
                                              12,
                                            "���������",
                                               70,
                                               140,
                                                90,
                                                6);
    loundSpeaker_enclosure *ptr_1 = 0;
    cout<<"----------------------------------------------------"<<endl;
    cout <<"show():\n";
    ptr_1= &Sp; //�������� ������ �������� ������ loundSpeaker_enclosure ��������� ���� loundSpeaker_enclosure
    ptr_1->show();  //����� ����������� ������� ������ loundSpeaker_enclosure
    ptr_1=&Speaker2; //�������� ������ ������ speaker_enclosure_derived ��������� ������ loundSpeaker_enclosure
    ptr_1->show();  //����� ����������� ������� ������ speaker_enclosure_derived
//  Sp.show();
//  Speaker2.show();
    cout<<"----------------------------------------------------"<<endl;
    cout <<"����������: <<\n";
    cout << Speaker2;
    cout<<"----------------------------------------------------"<<endl;
    return 0;
}

