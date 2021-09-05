#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include "loundspeaker_enclosure.hpp"
#include "speaker_enclosure_derived.hpp"
#include <fstream>
#include <vector>
#include "checklist.h"
using namespace std;


class menu
{
    checklist ls;
public:
    menu();
    ~menu();
    void open_menu(int& k, bool &check);
    void about() const;
    void readFile(checklist *ls,int &k,bool &check);
    friend class checklist;

};

#endif // MENU_HPP
