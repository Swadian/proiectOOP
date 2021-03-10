#pragma once

class nota{

protected:
int value;
string subject;

public:
note(int value, string subject)
{
    this->value=value;
    this->subject=subject;
};

void setValue(int value)
    {this->value=value;}
int getValue()
    {return this->value;}
void setSubject(string subject)
    {this->subject=subject;}



};

class medie : public nota{
double value;
bool passing;
public:
    void setValue(double value)
    {this->value=value;}
    double getValue()
    {return this->value;}
    bool isPassing()
    {return this->passing;}
    void setPassing(bool passing)
    {this->passing=passing;}




};

class clasa;
class elev;
class teacher{
    protected:
string subject;
clasa* clase;

};


class clasa{
teacher* profesori;
string* subjects;
elev* elevi;

};


class elev{

private:
    char* nume;
    char init_tata;
    string* materii;
    const int IDOrd;
    medie* medii;




public:
    static int contorID;

};
