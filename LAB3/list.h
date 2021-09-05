#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "speaker_enclosure_derived.hpp"

using std::cin;
using std::string;
using std::cout;

struct Node
{
   string param;
   Node *pred;
   Node *sled;
};

class List
{
    Node *Head=nullptr, *Tail = nullptr; //указатели на начало списка и его конец
public:
    List();
    ~List();
    void Show();
    void Add(string param);

private:

    List(const List&);  // запрещаем конструктор копирования
    List& operator=(const List&);  // запрещаем операцию присваивания
};

#endif // LIST_H
