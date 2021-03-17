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

class teacher{
    private:
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
        teacher& operator=(const teacher& t)
        {
            if(this!=&t)
            {
                if (this->nume!=NULL)
                    delete[] this->nume;
                if(this->prenume!=NULL);
                    delete[] this->prenume;
                this->nume=new char[strlen(t.nume)+1];
                strcpy(this->nume,t.nume);
                this->prenume=new string[2];
                this->prenume[0]=t.prenume[0];
                this->prenume[1]=t.prenume[1];
                this->subject=t.subject;
            }
            return *this;
        }
        teacher(const teacher& t)
        {
                this->nume=new char[strlen(t.nume)+1];
                strcpy(this->nume,t.nume);
                this->prenume=new string[2];
                this->prenume[0]=t.prenume[0];
                this->prenume[1]=t.prenume[1];
                this->subject=t.subject;
        }

};



class elev{

private:
    char* nume;
    string prenume;
    char init_tata;
    const int IDOrd;
    medie* medii;
    nota* note;
    int noteCount;
    int materii;
    float medieGenerala;
public:

    static int contorID;
    elev& operator=(const elev& e)
    {
        if(this!=&e)
        {
            if(this->nume!=NULL)
                delete[] this->nume;
            if(this->medii!=NULL)
                delete[] this->medii;
            this->nume=new char[strlen(e.nume)+1];
            strcpy(this->nume,e.nume);
            this->prenume=e.prenume;
            this->init_tata=e.init_tata;
            this->materii=e.materii;
            this->medii=new medie[e.materii];
            for(int i=0;i<e.materii;i++)
                this->medii[i]=e.medii[i];
            this->medieGenerala=e.medieGenerala;
            this->noteCount=e.noteCount;
            for(int i=0;i<e.noteCount;i++)
                this->note[i]=e.note[i];

        }
      return  *this;
    }
    elev( const elev& e):IDOrd(e.IDOrd)
    {
            if(this->nume!=NULL)
                delete[] this->nume;
            if(this->medii!=NULL)
                delete[] this->medii;
            if(this->note!=NULL)
                delete[] this->note;
            this->nume=new char[strlen(e.nume)+1];
            strcpy(this->nume,e.nume);
            this->prenume=e.prenume;
            this->init_tata=e.init_tata;
            this->materii=e.materii;
            this->medii=new medie[e.materii];
            for(int i=0;i<e.materii;i++)
                this->medii[i]=e.medii[i];
            this->medieGenerala=e.medieGenerala;
            this->noteCount=e.noteCount;
            for(int i=0;i<e.noteCount;i++)
                this->note[i]=e.note[i];
    }

    char* getNume()
    {return this->nume;}

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
        this->note=NULL;
        this->noteCount=0;
    }
    elev(char* nume,string prenume, char init_tata, int materii,
         medie* medii, float medieGenerala, nota *note, int noteCount):IDOrd(contorID++)
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
             this->note=new nota[noteCount];
             this->noteCount=noteCount;
             for(int i=0;i<noteCount;i++)
                this->note[i]=note[i];
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
float *medii;
public:
    clasa(teacher* profesori,int nrProfesori,
          elev *elevi,int nrElevi, teacher diriginte,
          int nrSali, int* sali, float *medii)
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
        this->medii=new float[nrElevi];
        for(int i=0;i<nrElevi;i++)
            this->medii[i]=medii[i];
    }
};

int main()
{
    return 0;
}
