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
                                        "пассивная",
                                        {"1 х 2.2",
                                        "1 х 10",
                                        "1 х 20"},
                                        "45 - 23",
                                        "черный",
                                        6);

    speaker_enclosure_derived Speaker2("YAMAHA NS-6490",
                                             70,
                                             140,
                                             "пассивная",
                                             {"1 х 2.2",
                                             "1 х 10",
                                             "1 х 20"},
                                             "45 - 23",
                                             "черный",
                                               6,
                                              12,
                                            "Индонезия",
                                               70,
                                               140,
                                                90,
                                                6);
    loundSpeaker_enclosure *ptr_1 = 0;
    cout<<"----------------------------------------------------"<<endl;
    cout <<"show():\n";
    ptr_1= &Sp; //передача адреса базового класса loundSpeaker_enclosure указателю типа loundSpeaker_enclosure
    ptr_1->show();  //вызов виртуальной функции класса loundSpeaker_enclosure
    ptr_1=&Speaker2; //передача адреса класса speaker_enclosure_derived указателю класса loundSpeaker_enclosure
    ptr_1->show();  //вызов виртуальной функции класса speaker_enclosure_derived
//  Sp.show();
//  Speaker2.show();
    cout<<"----------------------------------------------------"<<endl;
    cout <<"Перегрузка: <<\n";
    cout << Speaker2;
    cout<<"----------------------------------------------------"<<endl;
    return 0;
}

