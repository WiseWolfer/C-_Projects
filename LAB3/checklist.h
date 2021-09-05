#ifndef CHECKLIST_H
#define CHECKLIST_H

#include "speaker_enclosure_derived.hpp"

class checklist
{
    struct Data
    {
        speaker_enclosure_derived sp;
        Data* next;
        Data* priv;
    };

    Data *first = 0, *last =0;
private:
    checklist(const checklist&);  // запрещаем конструктор копирования
    checklist& operator=(const checklist&);  // запрещаем операцию присваивания
public:
    checklist();
    ~checklist();
    void add(speaker_enclosure_derived p, int &k);
    void del();
    void showAll( bool &check);
    void showCurrent(int n);

};

#endif // CHECKLIST_H
