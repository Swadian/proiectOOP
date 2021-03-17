#include <iostream>
#include <cstring>

using namespace std;


/*
int - nota.
bool - medie.
char - elev
char* - elev
float -elev
int* - clasa
float* -
double - medie
const - elev
static - elev
string - teacher
string* -teacher


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
nota()
{
    this->value=0;
    this->subject="";
}
void setValue(int value)
    {this->value=value;}
int getValue()
    {return this->value;}
void setSubject(string subject)
    {this->subject=subject;}
string getSubject()
{ return this->subject;}




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

medie()
{
    this->value=0;
    this->passing=false;
    this->subject="NONE";
}
medie(nota *note, int nr)
{
    double v=0;
    for (int i=0;i<nr;i++)
        v+=note[i].getValue();
    this->subject=note[0].getSubject();
    this->value=v/nr;
    if(this->value>=5.0) this->passing=true;
    else this->passing=false;
}


};
class elev;

class teacher{
    protected:
char* nume;
string *prenume;
string subject;
    public:
        teacher()
        {
            this->nume=new char[strlen("anonim")+1];
            strcpy(this->nume,"anonim");
            this->prenume=new string[2];
            this->prenume[0]="anonim";
            this->prenume[1]="";
            this->subject="NONE";
        }
        teacher(char *nume,string *prenume,string subject)
        {
            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
            this->prenume=new string[2];
            this->prenume[0]=prenume[0];
            this->prenume[1]=prenume[1];
            this->subject=subject;
        }
        ~teacher()
        {
            if(this->nume!=NULL)
                delete[] this->nume;
            if(this->prenume!=NULL)
                delete[] this->prenume;
        }
};



class elev{

private:
    char* nume;
    string prenume;
    char init_tata;
    const int IDOrd;
    medie* medii;
    int materii;
    float medieGenerala;
public:

    static int contorID;
    char* getNume()
    {

        return this->nume;

    }

    void setNume(char* nume)
    {

        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);

    }

    elev():IDOrd(contorID++)
    {
        this->nume=new char[strlen("Anonim")+1];
        strcpy(this->nume,"Anonim");
        this->prenume="Unknown";
        this->init_tata='?';
        this->medii=NULL;
        this->medieGenerala=0;
        this->materii=0;
    }
    elev(char* nume,string prenume, char init_tata, int materii,
         medie* medii, float medieGenerala):IDOrd(contorID++)
         {
             this->nume=new char[strlen(nume)+1];
             strcpy(this->nume,nume);
             this->prenume=prenume;
             this->init_tata=init_tata;
             this->materii=materii;
             this->medii=new medie[materii];
             for(int i=0;i<materii;i++)
                this->medii[i]=medii[i];
             this->medieGenerala=medieGenerala;
         }

         ~elev()
         {
             if(this->nume!=NULL)
                delete[] this->nume;
             if (this->medii!=NULL)
                delete[] this->medii;
         }
};
int elev::contorID=1000;

class clasa{
private:
teacher* profesori;
int nrProfesori;
elev* elevi;
int nrElevi;
teacher diriginte;
int* sali;
int nrSali;
public:
    clasa(teacher* profesori,int nrProfesori, elev *elevi,int nrElevi, teacher diriginte, int nrSali, int* sali)
    {
        this->nrProfesori=nrProfesori;
        this->profesori=new teacher[nrProfesori];
        for(int i=0;i<nrProfesori;i++)
            this->profesori[i]=profesori[i];
        this->nrElevi=nrElevi;
        this->elevi=new elev[nrElevi];
        for(int i=0;i<nrElevi;i++)
            this->elevi[i]=elevi[i];
        this->diriginte=diriginte;
        this->sali=new int[nrSali];
        this->nrSali=nrSali;
    }
};

int main()
{
    return 0;
}
