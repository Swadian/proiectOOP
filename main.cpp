#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


//database structure
class nota{

protected:
int value;
string subject;

public:
    friend ostream& operator<<(ostream& out, const nota& n);
    friend istream& operator>>(istream& in, nota& n);
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
void setValue(int value){this->value=value;}
int getValue(){return this->value;}
void setSubject(string subject){this->subject=subject;}
string getSubject(){return this->subject;}
const nota& operator++();
const nota operator++(int);
nota& operator=(const nota& n)
{
    if (this!=&n)
        {
            this->value=n.value;
            this->subject=n.subject;

        }
        return *this;
}
nota(nota& n)
{
            this->value=n.value;
            this->subject=n.subject;
}
bool operator==(const nota& n){return this->value==n.value;}
bool operator<(const nota& n){return this->value<n.value;}
nota operator+(int x)
{
    nota aux(*this);
    aux.value+=x;
    return aux;
}
nota* operator*(int x)
{
    nota* aux=new nota[x];
    for (int i=0;i>x;i++)
        aux[i]=*this;
    return aux;
}
};
ostream& operator<<(ostream& out, const nota& n){
out<<n.subject<<": "<<n.value;
return out;
}
istream& operator>>(istream& in, nota& n){
cout<<"materia: ";
in>>n.subject;
cout<<"\nNota: ";
in>>n.value;
return in;
}
const nota& nota::operator++()
{
    this->value++;
    return *this;
}
const nota nota::operator++(int)
{
    nota aux(*this);
    this->value++;
    return aux;
}



class medie : public nota
{
double value;
bool passing;
public:
    friend istream& operator>>(istream& in, medie& m);
    friend ostream& operator<<(ostream& out, const medie& m);
    void setValue(double value){this->value=value;}
    double getValue(){return this->value;}
    bool isPassing(){return this->passing;}
    void setPassing(bool passing){this->passing=passing;}

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
medie(double v,string sj)
{
    this->value=v;
    this->subject=sj;
    if(v>=5.0) this->passing=true;
    else this->passing=false;

}
explicit operator int(){return (int)this->value;}
medie& operator=(const medie& m)
{
    if(this!=&m)
    {
        this->value=m.value;
        this->subject=m.subject;
        this->passing=m.passing;
    }
    return *this;
}
medie(medie& m)
{
        this->value=m.value;
        this->subject=m.subject;
        this->passing=m.passing;
}

};

    istream& operator>>(istream& in, medie& m){
    cout<<"materia: ";
    in>>m.subject;
    cout<<"\nNota: ";
    in>>m.value;
    return in;
    }
    ostream& operator<<(ostream& out, const medie& m){
        out<<m.subject<<": "<<m.value;
        return out;
        }


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
                if(this->prenume!=NULL)
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
string getSubject(){return this->subject;}
friend istream& operator>>(istream& in, teacher& t);
friend ostream& operator<<(ostream& out, const teacher& t);
};
istream& operator>>(istream& in, teacher& t){
cout<<"Nume: ";
char aux[100];
in>>aux;
if(t.nume!=NULL)
    delete[] t.nume;
t.nume=new char[strlen(aux)+1];
strcpy(t.nume,aux);
cout<<"\nPrenume 1: ";
if(t.prenume!=NULL)
    delete[] t.prenume;
t.prenume=new string[2];
in>>t.prenume[0];
cout<<"\nPrenume 2(leave blank if N/A): ";
in>>t.prenume[1];
cout<<"\nMaterie predata: ";
in>>t.subject;
return in;
}
ostream& operator<<(ostream& out, const teacher& t){
out<<t.nume<<' '<<t.prenume[0]<<' '<<t.prenume[1]<<" profesor de "<<t.subject;
return out;
}


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
    friend istream& operator>>(istream&in, elev& e);
    friend ostream& operator<<(ostream& out, const elev& e);
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
    elev(char* nume,string prenume, char init_tata, int materii,medie* medii, float medieGenerala, nota *note, int noteCount):IDOrd(contorID++)
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

    char* getNume(){return this->nume;}
    void setNume(char* nume)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    float getMedieGenerala(){return this->medieGenerala;}
    void setMedieGenerala(float m){this->medieGenerala=m;}
    void setInitTata(char i){this->init_tata=i;}
    char getInitTata(){return this->init_tata;}
    int getMaterii(){return this->materii;}
    void setMaterii(int m){this->materii=m;}
    nota* getNote(){return this->note;}
    void setNote(nota* n, int k)
    {
        if(this->note!=NULL)
            delete[] this->note;
        this->note= new nota[k];
        for(int i=0;i<k;i++)
            this->note[i]=n[i];
        this->noteCount=k;
    }
    medie* getMedii(){return this->medii;}
    void setMedii(medie* n, int k)
    {
        if(this->medii!=NULL)
            delete[] this->medii;
        this->medii= new medie[k];
        for(int i=0;i<k;i++)
            this->medii[i]=n[i];
    }
    int getNoteCount(){return this->noteCount;}
};
int elev::contorID=1000;
istream& operator>>(istream& in, elev& e)
{
    char aux[100];
    cout<<"Nume: ";
    in>>aux;
    if(e.nume!=NULL)
        delete[] e.nume;
    e.nume=new char[strlen(aux)+1];
    strcpy(e.nume,aux);
    cout<<"\nPrenume: ";
    in>>e.prenume;
    cout<<"\nInitiala tata: ";
    in>>e.init_tata;
    cout<<"\nNumar materii studiate: ";
    in>>e.materii;
    cout<<"\nMedii: ";
    if(e.medii!=NULL)
        delete[] e.medii;
    e.medii = new medie[e.materii];
    for(int i=0;i<e.materii;i++)
        in>>e.medii[i];
    cout<<"\nNumar note: ";
    in>>e.noteCount;
    if(e.note!=NULL)
        delete[] e.note;
    e.note= new nota[e.noteCount];
    cout<<"\nNote: ";
    for(int i=0;i<e.noteCount;i++)
        in>>e.note[i];
    cout<<"\nMedia generala: ";
    in>>e.medieGenerala;
    return in;
}
ostream& operator<<(ostream& out, const elev& e)
{
    out<<e.IDOrd<<'\n';
    out<<"\nNume: "<<e.nume<<"\nPrenume: "<<e.prenume<<"\nInitiala Tatalui: "<<e.init_tata<<'.';
    out<<"\nMedii: ";
    for(int i=0;i<e.materii;i++) out<<e.medii[i]<<' ';
    out<<"\nNote: ";
    for(int i=0;i<e.noteCount;i++) out<<e.note[i]<<' ';
    out<<"\nMedia generala: "<<e.medieGenerala;
    return out;
}

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
    clasa()
    {
        profesori=NULL;
        nrProfesori=0;
        elevi=NULL;
        nrElevi=0;
        diriginte=teacher();
        sali=NULL;
        nrSali=0;

    }
    clasa(teacher* profesori,int nrProfesori,
          elev *elevi,int nrElevi, teacher diriginte,
          int nrSali, int* sali)
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
    clasa(const clasa& c)
    {
        this->nrProfesori=c.nrProfesori;
        this->profesori=new teacher[c.nrProfesori];
        for(int i=0;i<c.nrProfesori;i++)
            this->profesori[i]=c.profesori[i];
        this->nrElevi=c.nrElevi;
        this->elevi=new elev[c.nrElevi];
        for(int i=0;i<nrElevi;i++)
            this->elevi[i]=c.elevi[i];
        this->diriginte=c.diriginte;
        this->sali=new int[c.nrSali];
        this->nrSali=c.nrSali;
    }
    clasa& operator=(const clasa& c)
    {
        if(this!=&c)
        {
        this->nrProfesori=c.nrProfesori;
        if(this->profesori!=NULL) delete[] this->profesori;
        this->profesori=new teacher[c.nrProfesori];
        for(int i=0;i<c.nrProfesori;i++)
            this->profesori[i]=c.profesori[i];
        this->nrElevi=c.nrElevi;
        if(this->elevi!=NULL) delete[] this->elevi;
        this->elevi=new elev[c.nrElevi];
        for(int i=0;i<nrElevi;i++)
            this->elevi[i]=c.elevi[i];
        this->diriginte=c.diriginte;
        if(this->sali!=NULL) delete[] this->sali;
        this->sali=new int[c.nrSali];
        this->nrSali=c.nrSali;
        }
        return *this;
    }
    int* getSali(){return this->sali;}
    void setSali(int *sali, int nrSali)
    {
        if(this->sali !=NULL)
            delete[] this->sali;
        this->sali=new int[nrSali];
        this->nrSali=nrSali;
    }
    teacher* getTeachers(){return this->profesori;}
    void setTeachers(teacher* p, int np)
    {
        if(this->profesori!=NULL)
            delete[] this->profesori;
        this->profesori=new teacher[np];
        this->nrProfesori=np;
        for(int i=0;i<np;i++)
            this->profesori[i]=p[i];
    }
    void setElevi(elev* e, int nE)
    {
        if (this->elevi!=NULL)
            delete[] this->elevi;
        this->elevi= new elev[nE];
        this->nrElevi=nE;
        for(int i=0;i<nE;i++)
            this->elevi[i]=e[i];
    }
    elev* getElevi(){return this->elevi;}
    int getNrElevi(){return this->nrElevi;}
    int getNrProfesori(){return this->nrProfesori;}
    elev operator[](int index);
    friend istream& operator>>(istream& in, clasa& c);
    friend ostream& operator<<(ostream& out, const clasa& c);
};

    elev clasa::operator[](int index)
    {
        if(0<=index&&index<this->nrElevi)
            return elevi[index];
        else cout<<"index out of bounds";
        return elevi[0];

    }

istream& operator>>(istream& in, clasa& c)
{
    cout<<"Diriginte: ";
    in>>c.diriginte;
      cout<<"\nNr. profesori: ";
      in>>c.nrProfesori;
      if(c.profesori!=NULL)
        delete[] c.profesori;
      c.profesori=new teacher[c.nrProfesori];
      for(int i=0;i<c.nrProfesori;i++)
        in>>c.profesori[i];
      cout<<"\nNr. elevi: ";
      in>>c.nrElevi;
      if(c.elevi!=NULL)
        delete[] c.elevi;
      c.elevi = new elev[c.nrElevi];
      for(int i=0;i<c.nrElevi;i++)
        in>>c.elevi[i];
      cout<<"\nNr. Sali: ";
      in>>c.nrSali;
      if(c.sali!=NULL)
        delete[] c.sali;
      c.sali=new int[c.nrSali];
      for(int i=0;i<c.nrSali;i++)
        in>>c.sali[i];
      return in;
}
ostream& operator<<(ostream& out,const clasa& c)
{
    out<<"Diriginte: "<<c.diriginte<<'\n';
    out<<"Profesori:\n";
    for(int i=0;i<c.nrProfesori;i++)
        out<<c.profesori[i];
    out<<"Elevi:\n";
    for(int i=0;i<c.nrElevi;i++)
        out<<c.elevi[i];
    out<<"Sali:\n";
    for(int i=0;i<c.nrSali;i++)
        out<<c.sali[i]<<' ';
    return out;
}
//privileges and database operations
class privilege{
protected:
    int selectedClass=0;

public:
    virtual void checkStudent(elev &e)=0;

virtual void selectClass(int i){this->selectedClass=i;}
virtual void printClass(vector<clasa> &clase)=0;

};
class adminPrivilege:public privilege{
public:
virtual void checkStudent(elev &e)
{
    cout<<e;
}
void addClass(vector<clasa> &clase)
{
    clasa *c=new clasa();
    cin>>*c;
    clase.push_back(*c);
}
virtual void printClass(vector<clasa> &clase)
{cout<<clase[this->selectedClass];}
void addStudent(vector<clasa> &clase)
{
    clasa *c=&clase[this->selectedClass];
    elev* aux=new elev[c->getNrElevi()+1];
    for(int i=0;i<c->getNrElevi();i++)
        aux[i]=c->getElevi()[i];
    cin>>aux[c->getNrElevi()];
    c->setElevi(aux,c->getNrElevi()+1);
}
};
class studentPrivilege:public privilege{
elev *student;
public:
    studentPrivilege(elev &e)
        {this->student=&e;}
virtual void checkStudent(elev &e)
{
    cout<<e.getNume()<<'\n';
    cout<<e.getMedieGenerala()<<'\n';
    for(int i=0;i<e.getNoteCount();i++)
        cout<<e.getNote()[i];
    for(int i=0;i<e.getMaterii();i++)
        cout<<e.getMedii()[i];
}

};
class teacherPrivilege:public privilege{
string subject;
public:
teacherPrivilege(teacher t)
{
    this->subject=t.getSubject();
}
    virtual void checkStudent(elev &e)
{

    cout<<e.getNume()<<'\n';
    for(int i=0;i<e.getNoteCount();i++)
        if(e.getNote()[i].getSubject()==this->subject)
        cout<<e.getNote()[i];
    for(int i=0;i<e.getMaterii();i++)
            if(e.getMedii()[i].getSubject()==this->subject)
        cout<<e.getMedii()[i];

}
virtual void printClass(vector<clasa> &clase)
{
    clasa *c=&clase[this->selectedClass];
    for(int i=0;i<c->getNrElevi();i++)
        cout<<c->getElevi()[i];
}

};
class homeroomPrivilege:public teacherPrivilege{
virtual void checkStudent(const elev &e)
{
    cout<<e;
}


};

int main()
{
    vector<clasa> clase;
    privilege* level;
    cout<<"Login as:\n1.Admin\n2.teacher\n3.student\n";
    int i;
    cin>>i;
    switch(i){
case 1:
    {
        level=new adminPrivilege();
        break;
    }
    case 2:
        {
            teacher *t=new teacher();
            cin>>*t;
            level=new teacherPrivilege(*t);
            break;
        }
    case 3:
    {
     //   level=new studentPrivilege();
        break;
    }
    }
    return 0;
}
