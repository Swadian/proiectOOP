#include <iostream>
#include <cstring>

using namespace std;


/*
int - nota
bool - medie
char - elev
char* - elev
float -elev
int* - clasa
float* -
double - medie
const - elev
static - elev
string - teacher
string* -


*/

class nota{

protected:
int value;
string subject;

public:
nota(int value, string subject)
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

class medie : public nota
{
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
elev* elevi;
teacher diriginte;
int* sali;
};


class elev{

private:
    char* nume;
    string prenume;

    char init_tata;
    const int IDOrd;
    medie* medii;
    float medieGenerala;




public:
    static int contorID;

};


int main()
{
    return 0;
}
