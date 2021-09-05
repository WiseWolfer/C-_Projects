#include <iostream>
#include "loundspeaker_enclosure.hpp"
#include <windows.h>
#include "speaker_enclosure_derived.hpp"
#include "menu.hpp"
#include <fstream>
#include "checklist.h"
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("mode con cols=130 lines=30");

    int amount = 0;
    cout << "¬ведите количество строк в файле: ";
    cin >> amount;
    menu m;
    bool check = false;
    m.open_menu(amount,check);
    return 0;
}

