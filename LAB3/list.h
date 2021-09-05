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
    Node *Head=nullptr, *Tail = nullptr; //��������� �� ������ ������ � ��� �����
public:
    List();
    ~List();
    void Show();
    void Add(string param);

private:

    List(const List&);  // ��������� ����������� �����������
    List& operator=(const List&);  // ��������� �������� ������������
};

#endif // LIST_H
