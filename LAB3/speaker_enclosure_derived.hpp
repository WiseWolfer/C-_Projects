#ifndef SPEAKER_ENCLOSURE_H
#define SPEAKER_ENCLOSURE_H

#include "loundspeaker_enclosure.hpp"


class speaker_enclosure_derived: public loundSpeaker_enclosure  //����������� ������������ (��������������� ������)
{
private:
    int Guarantee;          //��������
    std::string country;    //������ �������������
    int Front_Power;        //����������� �������� (�����)
    int Front_Max_Power;    //������������ �������� (�����)
    int Front_sensitivity;  //���������������� (�����)
    int Front_Impedance;    //�������� (�����)

public:
    speaker_enclosure_derived(); //��������� ����������� �����������

    speaker_enclosure_derived(std::string lname,
                            int lTotal_rated_power,
                            int lTotal_max_power,
                            std::string lpassive,
                            const LSize lsize,
                            int lcost,
                            std::string lfrequency_range,
                            int lGuarantee,
                            std::string lcountry,  //��������� ����������� � �����������
                            int lFront_Power,
                            int lFront_Max_Power,
                            int lFront_sensitivity,
                            int lFront_Impedance);


    virtual~speaker_enclosure_derived();   //��������� ����������

   friend std::ostream& operator<<(std::ostream& os, const speaker_enclosure_derived* n); //���������� ������������� �������
    //��������� ����� ������� ��� ���������������� ������                                        //(������� �� �������� ������ ������,�� ����� ��������
                                                                                                 //� ��� �������)
    //������ ������
    void setGuarantee(const int  lGuarantee);
    int getGuarantee() const;

    void setcountry(const std::string lcountry);
    std::string getcountry() const;

    void setFront_Power(const int lFront_Power);
    int getFront_Power() const;

    void setlFront_Max_Power(const int lFront_Max_Power);
    int getFront_Max_Power() const;

    void setFront_sensitivity(const int lFront_sensitivity);
    int getFront_sensitivity() const;

    void setFront_Impedance(const int  lFront_Impedance);
    int getFront_Impedance() const;

    void f_derived_open(speaker_enclosure_derived &k, const string& str);
    void show_derived(speaker_enclosure_derived* n, const int& k);
    void show() const;
};


#endif // SPEAKER_ENCLOSURE_H
