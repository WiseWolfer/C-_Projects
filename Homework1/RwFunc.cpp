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
    fstream in("spisok.txt", ios_base::in); //открываем файловый поток для ввода

    if(!in.is_open())
    {
        cerr << "Ошибка: Файл не открыт!"<< endl;
        return;

    }
    if(Open){
        cerr <<"Ошибка: Файл уже открыт!"<< endl;
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

    #if __WINNT__   //макрос очистки экрана для windows
        system("cls");
    #else               // для других систем очистка(linux,mac os и др.)
        system("clear");
    #endif

    cout<<"\n\nФайл успешно открылся!\n"<< endl;

}
void convertSTR(string str, struct Petrol &gazik)
{
    int indexNow,indexLast = 0;

    string t1,t2,t3,t4,t5,t6;

    indexNow = str.find(';',indexLast); //записываем в indexNow (номер символа ;)

    for(int i = indexLast; i < indexNow; i++)
        t1+=str[i];             //записываем сроку в t1

     gazik.nomer = stoi(t1);    //конвертируем в чилсо
     indexLast = indexNow + 1;          //встаем на след строку после ; и записываем в indexLast число
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

void F_Write(Petrol* gaz,int &NC){  //Записать файл

    fstream out("spisok.txt", ios_base::out);   //открываем файловый поток для вывода
    if(!out.is_open())
    {
         cerr << "Error: Файл не открыт!" << endl;
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
    cout << "\n\n Файл был записан \n" <<endl;
}

void F_Add(Petrol* gaz,int &NC,bool &Open)    //Добавить новую запись в структурный массив
{
    if(!Open){
        cerr << "Ошибка: Файл не был открыт!" << endl;
        return;
    }
    #if __WINNT__
        system("cls");
    #else
        system("clear");
    #endif
    Petrol gazik;
    cout << "\n\n Добавление элемента \n Введите:"<<endl;
    cout  <<"\tНомер записи: ";cin >> gazik.nomer;
    cout  <<"\tФИО: ";_flushall();getline(cin , gazik.fio);
    cout  <<"\tДата дежурства: "; _flushall();getline(cin , gazik.data);
    cout  <<"\tМарка_бензина: ";_flushall();getline(cin , gazik.benzin_marks);  //flushall:приводит к записи cодержимого всех выходных буферов,
    cout  <<"\tОбъём проданного бензина за смену: ";cin >> gazik.volume;    // связан­ных с потоками файлов, в файлы и к очистке всех входных буферов.
    cout  <<"\tВыручка за смену: ";cin >> gazik.income;
    gaz[NC] = gazik;
    NC++;
}
void F_Delete(Petrol* gaz,int &NC,bool &Open) //Удаление из массива
{
    if(!Open){
        cerr << "Ошибка:  Файл не открыт!" << endl;
        return;
    }

    #if __WINNT__
    system("cls");
    #else
    system("clear");
    #endif
    bool found = false;
    int DelNom = -1;
    cout << "\n\n Удаление элемента \n Введите ID удаляемого элемента:";
    cin >> DelNom;
    for(int i = 0; i < NC; i++)
    {
        if(gaz[i].nomer == DelNom)  //записываем конкретный номер записи из 10 для удаления
        {
            found =true;
            break;
        }
        else
           continue;    //переход на след. итерацию цикла, пропуская запись удаляемого элемента
    }

    //if(DelNom <= 10 && DelNom > 0)
    if(found)
    {
        for(int i = DelNom - 1;i < NC - 1;i++ ) //когда удаляема запись существует (1-10)
        {
            gaz[i] = gaz[i+1];                  //идет ее перезапись и удаление
        }
        NC--;
        cout << "\n Элемент удален \n"<<endl;
    }
    else{
        cout << "\n Элемент с заданным ID не найден\n"<<endl;
    }
}
