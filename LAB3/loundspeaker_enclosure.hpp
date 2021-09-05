#ifndef LOUNDSPEAKER_ENCLOSURE_H
#define LOUNDSPEAKER_ENCLOSURE_H
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
class loundSpeaker_enclosure    //����������� ������� �����
{                                   //����������� ������� �����

public:
    struct LSize
    {
        std::string RF_speakers;  //�� �������� (�����)
        std::string Midrange_speakers; //�� �������� (�����)
        std::string bass_speakers; //�� �������� (�����)
    };            //������������ ��� �������� �������, ����������� ���������� ������ � ������, ���������� � ����, � ������ � ������ ������
                  //���������� �� ������������(���������� ������)

private:                    //���������� - ��� ������ �������� ����� �������� ������������� �������, �������� �� ������������ ����������.
    std::string name;   //�������� ������������� �������
    int Total_rated_power;  //��������� ����������� ��������
    int Total_max_power;    //��������� ������������ ��������
    std::string passive;    //��� ������������ �������
    LSize size;      //���������� ���������, ��� �������� ������� ��,��, ��.
    int cost;
    std::string frequency_range; //�������� ������ (�����)

public:
     friend class speaker_enclosure_derived;    //����� �������� ������� ������ � ������� ������ �������� � � ������ private
     loundSpeaker_enclosure();
     loundSpeaker_enclosure(std::string lname,
                            int lTotal_rated_power,
                            int lTotal_max_power,
                            std::string lpassive,
                            const LSize lsize,
                            int lcost,
                            std::string lfrequency_range);


     loundSpeaker_enclosure(const loundSpeaker_enclosure &other);   //��������� ����������� �����������

     virtual~loundSpeaker_enclosure();

     //������ ������

        void setTotal_rated_power(const int lTotal_rated_power);
        int getTotal_rated_power() const;

        void setpassive(const std::string lpassive);
        std::string getpassive() const;

        void setTotal_max_power(const int lTotal_max_power);
        int getTotal_max_power() const;

        void setSize(const LSize lsize);
        LSize getSize() const;

        void setfrequency_range(const std::string lfrequency_range);
        std::string getfrequency_range() const;

        void setname(const std::string lname);
        std::string getname() const;

        void setcost(const int lcost);
        int getcost() const;

        void f_open(loundSpeaker_enclosure &l,const string& str);


        void show_puk(loundSpeaker_enclosure* p, const int& k);
        void Massive_of_classes(loundSpeaker_enclosure* p);

         virtual void show() const; //����������� ������������
};

#endif // LOUNDSPEAKER_ENCLOSURE_H
