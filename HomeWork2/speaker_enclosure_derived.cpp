#include "speaker_enclosure_derived.hpp"
#include "loundspeaker_enclosure.hpp"

speaker_enclosure_derived::speaker_enclosure_derived():    //����������� �����������
    loundSpeaker_enclosure()
    ,Guarantee(0)
    ,country("")
    ,Front_Power(0)
    ,Front_Max_Power(0)
    ,Front_sensitivity(0)
    ,Front_Impedance(0)
{

}

speaker_enclosure_derived::speaker_enclosure_derived(std::string lname,
                                                     int lTotal_rated_power,
                                                     int lTotal_max_power,
                                                     std::string lpassive,
                                                     const LSize lsize,
                                                     std::string lfrequency_range,
                                                     std::string lcolour,
                                                     int lweight_of_frontal_speaker,
                                                     int lGuarantee,
                                                     std::string lcountry,  //����������� � �����������
                                                     int lFront_Power,
                                                     int lFront_Max_Power,
                                                     int lFront_sensitivity,
                                                     int lFront_Impedance):
    loundSpeaker_enclosure(lname
                           ,lTotal_rated_power
                           ,lTotal_max_power
                           ,lpassive
                           ,lsize
                           ,lfrequency_range
                           ,lcolour
                           ,lweight_of_frontal_speaker)
    ,Guarantee(lGuarantee)
    ,country(lcountry)
    ,Front_Power(lFront_Power)
    ,Front_Max_Power(lFront_Max_Power)
    ,Front_sensitivity(lFront_sensitivity)
    ,Front_Impedance(lFront_Impedance)
{

}


speaker_enclosure_derived::~speaker_enclosure_derived() //����������
{

}


void speaker_enclosure_derived::setGuarantee(const int lGuarantee)
{
    Guarantee =lGuarantee;
}

int speaker_enclosure_derived::getGuarantee() const
{
    return Guarantee;
}

void speaker_enclosure_derived::setcountry(const std::string lcountry)
{
        country = lcountry;
}

std::string speaker_enclosure_derived::getcountry() const
{
    return country;
}

void speaker_enclosure_derived::setFront_Power(const int lFront_Power)
{
    Front_Power=lFront_Power;
}

int speaker_enclosure_derived::getFront_Power() const
{
    return Front_Power;
}

void speaker_enclosure_derived::setlFront_Max_Power(const int lFront_Max_Power)
{
    Front_Max_Power=lFront_Max_Power;
}

int speaker_enclosure_derived::getFront_Max_Power() const
{
    return Front_Max_Power;
}

void speaker_enclosure_derived::setFront_sensitivity(const int lFront_sensitivity)
{
    Front_sensitivity=lFront_sensitivity;
}

int speaker_enclosure_derived::getFront_sensitivity() const
{
    return Front_sensitivity;
}

void speaker_enclosure_derived::setFront_Impedance(const int lFront_Impedance)
{
    Front_Impedance =lFront_Impedance;
}

int speaker_enclosure_derived::getFront_Impedance() const
{
    return Front_Impedance;
}

void speaker_enclosure_derived::show() const            //����� show() ��� ��������� ������
{
    cout <<"9) ��������: " <<Guarantee<< "\n"
         << "10) ������ �������������: " << country << "\n"
         <<"11) ����������� �������� (�����): "<<Front_Power<<" �� " <<"\n"
         << "12) ������������ �������� (�����): " << Front_Max_Power << " �� " <<"\n"
         << "13) �������� ������ (�����): " << Front_sensitivity<< " ��� \n"
         << "14) �������� (�����): " << Front_Impedance << " �� " << endl;
}
/*
    void operator<<(ostream& os, const speaker_enclosure_derived& Speaker)
    {
             os<<"1) �������� ������������� �������: "<<Speaker.getname();
             os<< "2) ����� ����������� ��������: " <<Speaker.getTotal_rated_power();
             os<<"3) ����� ������������ ��������: "<<Speaker.getTotal_max_power();
             os<< "4) ��� ������������� �������: " << Speaker.getpassive();
             os<< "5) ����������� ��: "<< Speaker.getSize().RF_speakers<<Speaker.getSize().Midrange_speakers
                  <<Speaker.getSize().bass_speakers;
             os<< "6) �������� ������: " << Speaker.getfrequency_range();
             os << "7) ����: " << Speaker.getcolour();
             os<< "8) ��� ����������� �������: " << Speaker.getweight_of_frontal_speaker();
             os << "9) ��������: " <<Speaker.getGuarantee()<<" ������� ";
             os << "10) ������ �������������: " << Speaker.getcountry();
             os << "11) ����������� �������� (�����): "<<Speaker.getFront_Power();
             os << "12) ������������ �������� (�����): " << Speaker.getFront_Max_Power();
             os << "13) ���������������� (�����): " << Speaker.getFront_sensitivity();
             os << "14) �������� (�����): " << Speaker.getFront_Impedance();
    }
*/
ostream& operator<<(ostream& os, const speaker_enclosure_derived& Speaker)    //���������� �������� ��������� � �����
{
             os<<"1) �������� ������������� �������: "<<Speaker.getname()<< endl;
             os<< "2) ����� ����������� ��������: " <<Speaker.getTotal_rated_power()<<" �� "<< endl;
             os<<"3) ����� ������������ ��������: "<<Speaker.getTotal_max_power()<<" �� " <<endl;
             os<< "4) ��� ������������� �������: " << Speaker.getpassive() << endl;
             os<< "5) ����������� ��: ("<< Speaker.getSize().RF_speakers <<"��, "<<Speaker.getSize().Midrange_speakers<<
                  "��, "<<Speaker.getSize().bass_speakers<<"�� )"<<endl;
             os<< "6) �������� ������: " << Speaker.getfrequency_range() << " ���"<<endl;
             os << "7) ����: " << Speaker.getcolour() << endl;
             os<< "8) ��� ����������� �������: " << Speaker.getweight_of_frontal_speaker()<<" �� " << endl;
             os << "9) ��������: " <<Speaker.getGuarantee()<<" ������� " << endl;        //�����������
             os << "10) ������ �������������: " << Speaker.getcountry() << endl;
             os << "11) ����������� �������� (�����): "<<Speaker.getFront_Power()<<" �� " <<endl;
             os << "12) ������������ �������� (�����): " << Speaker.getFront_Max_Power()<< " �� " <<endl;
             os << "13) ���������������� (�����): " << Speaker.getFront_sensitivity()<< " �� "<<endl;
             os << "14) �������� (�����): " << Speaker.getFront_Impedance() << " �� " << endl;
    return os;
}





