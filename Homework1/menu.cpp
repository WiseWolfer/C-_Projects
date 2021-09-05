#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <Windows.h>
#include "RwFunc.hpp"
#include "menu.hpp"
#include "locale.h"
using namespace std;

string fix( float x, int p )    //функция для правильного вывода зарплаты типа float
{
    ostringstream strout;
    strout << fixed << setprecision(p) << x ;
    string str = strout.str() ;
    return str;
    }
void Print_to_Screen(Petrol* gaz,int &NC)
{
    #if __WINNT__
        system("cls");
    #else
        system("clear");
    #endif

    ostringstream strout;

    for(int i=0;i<NC;i++)
    {
        cout << setw (3)<<gaz[i].nomer<<setw (34)
             <<gaz[i].fio<< setw (16)<<gaz[i].data
             <<setw (10)<<gaz[i].benzin_marks
             <<setw (8)<<gaz[i].volume<<setw (15)<<fix(gaz[i].income,2)<<endl;

    }
//    cout << setw (3) << provider[i].nomer;  -> setw (3) -ставим количество символов на строку с помощью setw в скобках, вместо табуляции.
}
void FuncAbout(){
    #if __WINNT__
        system("cls");
    #else
        system("clear");
    #endif

    cout << "Программу создал: Сбродов Дмитрий Владимирович\nНомер группы и курс: ЭУИС 2-4 \nТема работы: Автозаправка " << endl;
}
int FuncMenu(Petrol* gaz,int &NC,bool &Open)
{
    char n;
    while(true){
    #if __WINNT__
        system("cls");
    #else
        system("clear");
    #endif
    cout <<  "1)Прочитать Файл.\n2)Записать в Файл.\n"
             "3)Удалить запись из Файла.\n4)Добавить запись в Файл."
             "\n5)О программе.\n6)Вывести на экран.\nq)Выход."<<endl;
     cin >> n;

    #if __WINNT__
        system("cls");
    #else
        system("clear");
    #endif

       switch(n)
       {
        case 49:        //49 ('1')
            Read_File_1(gaz,NC,Open);
            break;
        case 50:         //50('2')
             F_Write(gaz,NC);
             break;
        case 51:         //51('3')
             F_Delete(gaz,NC,Open);
            break;
        case 52:         //52('4')
            F_Add(gaz,NC,Open);
            break;
        case 53:         //53('5')
            FuncAbout();
            break;
        case 54:        //54('6')
           Print_to_Screen(gaz,NC);
            break;
        case 113:       //113 ('q')
            return EXIT_SUCCESS;
            break;

      default:
            cerr <<"Ошибка: команды не "
                << " существует в этом меню!" << endl;
            break;
        }
      system("pause");
    }
}

