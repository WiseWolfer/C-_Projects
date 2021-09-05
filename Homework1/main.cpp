#include <iostream>
#include <string>
#include <cstring>
#include "RwFunc.hpp"
#include "menu.hpp"
#include <Windows.h>

using namespace std;


int main()
{
    system("mode con cols=120 lines=20");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int NC=0;
    bool Open = 0;
    Petrol gaz[100];   //задаю структурный массив


    FuncMenu(gaz,NC,Open);
    return 0;
}
