#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <list>
#include <iomanip>
#include <iterator>
#include <ctime>
#include <fstream>
#include <exception>
#include <map>
#include <vector>
#include <set>


using namespace std;

class AjutorClase /// Clasa abstracta
{
    virtual void Help()=0;
    virtual void NumeClasa()
    {
        cout<<"AjutorClase";
    }
};


class Calendar:public AjutorClase
{
private:
    const char *luni[12];
    int* zile_in_luna;
    bool an_bisect;
    char* data_timp_curent;
    float cod;
protected:
    int an, luna;


public:
    //constructorul fara parametrii
    Calendar():luni{"Ianuarie","Februarie","Martie","Aprilie","Mai","Iunie","Iulie","August","Septembrie","Octombrie","Noiembrie","Decembrie"}
    {
        an = 2020;
        luna = 0;

        // data/timp curent bazat pe sistemul pe care ruleaza
        time_t now = time(0); // cod preluat de pe https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

        //conversie in forma string
        data_timp_curent = ctime(&now);

        zile_in_luna = new int[12];
        zile_in_luna[0] = 31;
        Setter_februarie();
        zile_in_luna[2] = 31;
        zile_in_luna[3] = 30;
        zile_in_luna[4] = 31;
        zile_in_luna[5] = 30;
        zile_in_luna[6] = 31;
        zile_in_luna[7] = 31;
        zile_in_luna[8] = 30;
        zile_in_luna[9] = 31;
        zile_in_luna[10] = 30;
        zile_in_luna[11] = 31;

        cod = Getter_Setter_Codul_zilei();

    }
    //constructor cu parametrii
    Calendar(int an,int luna):luni{"Ianuarie","Februarie","Martie","Aprilie","Mai","Iunie","Iulie","August","Septembrie","Octombrie","Noiembrie","Decembrie"}
    {
        this->an = an;
        this->luna = luna;
        // data/timp curent bazat pe sistemul pe care ruleaza
        time_t now = time(0); // cod preluat de pe https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

        //conversie in forma string
        data_timp_curent = ctime(&now);

        zile_in_luna = new int[12];
        zile_in_luna[0] = 31;
        Setter_februarie();
        zile_in_luna[2] = 31;
        zile_in_luna[3] = 30;
        zile_in_luna[4] = 31;
        zile_in_luna[5] = 30;
        zile_in_luna[6] = 31;
        zile_in_luna[7] = 31;
        zile_in_luna[8] = 30;
        zile_in_luna[9] = 31;
        zile_in_luna[10] = 30;
        zile_in_luna[11] = 31;

        this->cod = Getter_Setter_Codul_zilei();
    }
    //constructor cu parametrii numarul 2
    Calendar(int an,int luna,bool an_bisect,float cod,int zile_in_luna[12]):luni{"Ianuarie","Februarie","Martie","Aprilie","Mai","Iunie","Iulie","August","Septembrie","Octombrie","Noiembrie","Decembrie"}
    {
        this->an = an;
        this->luna = luna;
        this->an_bisect = an_bisect;
        this->cod = cod;

        // data/timp curent bazat pe sistemul pe care ruleaza
        time_t now = time(0); // cod preluat de pe https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

        //conversie in forma string
        data_timp_curent = ctime(&now);

        this->zile_in_luna = new int[12];
        for(int i = 0;i<12;i++)
        {
            this->zile_in_luna[i] = zile_in_luna[i];
        }
    }
    //constructor de copiere
    Calendar(const Calendar &c2)
    {
        an = c2.an;
        luna = c2.luna;
        cod = c2.cod;

        an_bisect = c2.an_bisect;

        data_timp_curent = c2.data_timp_curent;

        zile_in_luna = new int[12];
        for(int i = 0;i< 12;i++)
        {
            zile_in_luna[i] = c2.zile_in_luna[i];
        }
        for(int i = 0;i< 12;i++)
        {
            luni[i] = c2.luni[i];
        }
    }

    //setteri
    void Setter_an(int an_dorit)
    {
        an = an_dorit;
    }

    void Setter_luna(int luna_dorita)
    {
        luna = luna_dorita;
    }

    void Setter_an_bisect(bool an_bisect)
    {
        this->an_bisect = an_bisect;
    }

    void Setter_februarie()
    {
        an_bisect = Verifica_an_bisect();
        if(an_bisect == true)
        {
            zile_in_luna[1] = 29;
        }else if(an_bisect == false)
        {
            zile_in_luna[1] = 28;
        }
    }

    //getteri
    int Getter_an()
    {
        return an;
    }

    int Getter_luna()
    {
        return luna;
    }

    int Getter_zile_in_luna(int luna)
    {
        return zile_in_luna[luna];
    }

    const char* Getter_luni(int luna)
    {
        return luni[luna];
    }

    float Getter_Setter_Codul_zilei()
    {
        int a;
        int l;
        int z;

        float cod_temporar;

        a =(this->an - 1)/4;      // formula preluata de pe https://www.codingunit.com/how-to-make-a-calendar-in-c
        l =(this->an - 1)/100;
        z =(this->an - 1)/400;
        cod_temporar = (an + a - l + z)%7;

        if(this->luna != 0)
        {
            for(int i=1;i<=this->luna;i++)
            {
                cod_temporar = (int(cod_temporar) + this->zile_in_luna[i-1])%7;
            }

        }
        if(cod_temporar == 0)
        {
            cod_temporar = 7;
        }
        return cod_temporar-1;
    }

    //functii
    bool Verifica_an_bisect()
    {
        if(an%4 == 0 || an%100 != 0 && an%400 == 0) // formula preluata de pe https://www.codingunit.com/how-to-make-a-calendar-in-c
        {
            return true;
        }
        return false;
    }

    void Data_curenta()
    {
        // data/timp curent bazat pe sistemul pe care ruleaza
        time_t now = time(0); // cod preluat de pe https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

        //conversie in forma string
        data_timp_curent = ctime(&now);
        cout << "Data locala si timpul actual sunt: " << data_timp_curent << endl;
    }

    void Help()override
    {
        cout<<"Clasa Calendar se ocupa de: \nSetarea lunilor dintr-un an\nCalculul anilor bisecti\nCalculul zilei de inceput a oricarui an\nPreluarea datii si a timpului curent";
    }

    void NumeClasa()override
    {
        cout<<"\nCalendar";
    }

    //operatori
     Calendar& operator=(Calendar& c2)
    {
        an = c2.an;
        luna = c2.luna;
        cod = c2.cod;

        an_bisect = c2.an_bisect;

        data_timp_curent = c2.data_timp_curent;

        zile_in_luna = new int[12];
        for(int i = 0;i< 12;i++)
        {
            zile_in_luna[i] = c2.zile_in_luna[i];
        }
        for(int i = 0;i< 12;i++)
        {
            luni[i] = c2.luni[i];
        }

        return *this;
    }
    int operator[](int index)
    {
        if(index<12 && index>0)
            return this->zile_in_luna[index];
        else
        {
                cout<<"Index invalid";
                return -1;
        }
    }
    Calendar& operator++(int valoare)
    {
        valoare = 1;

        Calendar c(an+valoare,luna);

        *this = c;

        return *this;
    }
    Calendar& operator++()
    {
        int valoare = 1;

        Calendar c(an+valoare,luna);

        *this = c;

        return *this;
    }
    Calendar& operator+(int valoare)
    {
        if(luna+valoare > 11)
        {
            luna = luna + valoare - 12;
        }else
        {
            luna += valoare;
        }

        return *this;
    }
    Calendar& operator-(int valoare)
    {
        if(luna - valoare < 0)
        {
            luna = 12 + luna - valoare;
        }else
        {
            luna -= valoare;
        }


        return *this;
    }
    operator int() const
    {
        return an*365 + an/4;
    }
    bool operator >=(Calendar& c)
    {
        if(an>=c.an)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator ==(Calendar& c)
    {
        if(an==c.an)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    friend ostream& operator<<(ostream& os, const Calendar& c);
    friend istream& operator>>(istream& is, Calendar& c);

    //destructor
    ~Calendar()
    {
      if(zile_in_luna != NULL)
      {
          delete [] zile_in_luna;
      }
    };
};
istream& operator>>(istream& is, Calendar& c)
{
        const char *luni[12] = {"Ianuarie","Februarie","Martie","Aprilie","Mai","Iunie","Iulie","August","Septembrie","Octombrie","Noiembrie","Decembrie"};
        int zile_in_luna[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int an, luna;
        cout<<"Introduceti anul si luna dorita(ex 2020 1): ";

        is>>an>>luna;


        while(luna < 1 || luna >12 || an < 1 || !cin)
        {

            cout<<endl<<"!!!Ceva a fost introdus gresit!!!"<<endl;
            is.clear();
            is.ignore(100,'\n');
            cout<<endl<<"Introduceti anul si luna dorita(ex 2020 1): ";
            is>>an>>luna;

        }


        c.Setter_an(an);
        c.Setter_luna(luna - 1);
        c.Getter_Setter_Codul_zilei();

        time_t now = time(0);
        c.data_timp_curent = ctime(&now);

        c.zile_in_luna = new int[12];
        for(int i = 0;i<12;i++)
        {
            c.zile_in_luna[i] = zile_in_luna[i];
        }

        for(int i = 0;i< 12;i++)
        {
            c.luni[i] = luni[i];
        }
        c.Setter_februarie();

        return is;
}
ostream& operator<<(ostream& os, const Calendar& c)
{
    os <<endl<<"Anul: "<< c.an<<endl;
    os <<endl<<"Luna: "<< c.luna + 1<<endl;
    os <<endl<<"Codul lunii(cod folosit pentru a calcula in ce zi incepe orice luna): "<< c.cod<<endl;
    os <<endl<<"Anul este bisect? : ";
    if(c.an_bisect)
    {
        os<<"Da";
    }else
    {
        os<<"Nu";
    }

    os <<endl<<"Data si timpul actual: "<< c.data_timp_curent<<endl;
    os <<endl<<"Lunile si cate zile are luna: "<<endl;
    for(int i = 0;i<12;i++)
    {
        os<<"Luna "<<c.luni[i]<<" are "<<c.zile_in_luna[i]<<" zile."<<endl;
    }


    return os;
}



class CalendarZodiac:public Calendar ///Clasa derivata de tipul IS A (mosteneste si AjutorClase, deoarece Calendar mosteneste AjutorClase)
{
private:
    string zodii[12] = {"Capricorn","Varsator","Pesti","Berbec","Taur","Gemeni","Rac","Leu","Fecioara","Balanta","Scorpion","Sagetator"};


public:
    //constructori
    CalendarZodiac(Calendar c):Calendar(c)
    {

    }
    //functii
    string Afla_zodie(int zi)
    {
        switch(this->luna) /// luna este protected in Calendar
        {
            case 0:
                switch(zi)
                {
                    case 1 ... 19:
                        return zodii[0];
                        break;
                    case 20 ... 31:
                        return zodii[1];
                        break;
                }
                break;

            case 1:
                switch(zi)
                {
                    case 1 ... 18:
                        return zodii[1];
                        break;
                    case 19 ... 29:
                        return zodii[2];
                        break;
                }
                break;

            case 2:
                switch(zi)
                {
                    case 1 ... 20:
                        return zodii[2];
                        break;
                    case 21 ... 31:
                        return zodii[3];
                        break;
                }
                break;

            case 3:
                switch(zi)
                {
                    case 1 ... 20:
                        return zodii[3];
                        break;
                    case 21 ... 30:
                        return zodii[4];
                        break;
                }
                break;

            case 4:
                switch(zi)
                {
                    case 1 ... 21:
                        return zodii[4];
                        break;
                    case 22 ... 31:
                        return zodii[5];
                        break;
                }
                break;

            case 5:
                switch(zi)
                {
                    case 1 ... 21:
                        return zodii[5];
                        break;
                    case 22 ... 30:
                        return zodii[6];
                        break;
                }
                break;

            case 6:
                switch(zi)
                {
                    case 1 ... 21:
                        return zodii[6];
                        break;
                    case 22 ... 31:
                        return zodii[7];
                        break;
                }
                break;

            case 7:
                switch(zi)
                {
                    case 1 ... 22:
                        return zodii[7];
                        break;
                    case 23 ... 31:
                        return zodii[8];
                        break;
                }
                break;

            case 8:
                switch(zi)
                {
                    case 1 ... 22:
                        return zodii[8];
                        break;
                    case 23 ... 30:
                        return zodii[9];
                        break;
                }
                break;

            case 9:
                switch(zi)
                {
                    case 1 ... 22:
                        return zodii[9];
                        break;
                    case 23 ... 31:
                        return zodii[10];
                        break;
                }
                break;

            case 10:
                switch(zi)
                {
                    case 1 ... 21:
                        return zodii[10];
                        break;
                    case 22 ... 30:
                        return zodii[11];
                        break;
                }
                break;

            case 11:
                switch(zi)
                {
                    case 1 ... 21:
                        return zodii[11];
                        break;
                    case 22 ... 31:
                        return zodii[0];
                        break;
                }
                break;
        }
    }

    void Help()override
    {
        cout<<"Clasa CalendarZodiac se ocupa de: \nCalculul zodiei pentru fiecare zi din orice luna";
    }

    void NumeClasa()override
    {
        cout<<"\nCalendarZodiac";
    }

};


class Agenda:public AjutorClase
{
private:
    int an, luna, zi;
    char* descriere_zi;
    char input[500];
    bool zi_ocupata;
    static int nr_zile_ocupate;


public:
    //constructor fara parametrii
    Agenda()
    {
        an = 2020;

        luna = 1;

        zi = 1;

        strcpy(input,"");

        zi_ocupata = false;

        //descriere_zi = new char[strlen("Ocupatie") + 1];

        descriere_zi = "Ocupatie";


        nr_zile_ocupate=0;
    }
    //constructor cu parametrii 1
    Agenda(int an,int luna,int zi,char* descriere_zi)
    {
        this->an = an;
        this->luna = luna;
        this->zi = zi;
        this->descriere_zi = descriere_zi;
        zi_ocupata = true;
        nr_zile_ocupate++;
        strcpy(input,"");
    }
    //constructor cu parametrii 2
    Agenda(int an,int luna,int zi,char* descriere_zi,bool zi_ocupata,char input[500],int nr_zile_ocupate)
    {
        this->an = an;
        this->luna = luna-1;
        this->zi = zi;
        this->descriere_zi = descriere_zi;
        this->zi_ocupata = zi_ocupata;
        this->nr_zile_ocupate++;
        for(int i = 0;i<500;i++)
        {
            this->input[i] = input[i];
        }

    }
    //constructor de copiere
    Agenda(const Agenda& ag)
    {
        an = ag.an;
        luna = ag.luna;
        zi = ag.zi;


        strcpy(input,ag.input);

        zi_ocupata = ag.zi_ocupata;

        descriere_zi = new char[strlen(ag.descriere_zi)];
        strcpy(descriere_zi,ag.descriere_zi);


    }

    //getteri
    int Getter_zi()
    {
       return zi;
    }

    int Getter_luna()
    {
       return luna;
    }

    int Getter_an()
    {
       return an;
    }

    bool Getter_zi_ocupata()
    {
        return zi_ocupata;
    }

    char* Getter_descriere_zi()
    {
        return descriere_zi;
    }

    char* Getter_input()
    {
        return input;
    }

    static int Getter_nr_zile_ocupate()
    {
        return nr_zile_ocupate;
    }

    //setteri
    void Setter_an(int an)
    {
        this->an = an;
    }

    void Setter_luna(int luna)
    {
        this->luna = luna;
    }

    void Setter_zi(int zi)
    {
        this->zi = zi;
    }

    void Setter_input(char* input)
    {
        strcpy(this->input,input);
    }

    void Setter_descriere_zi()
    {
        this->descriere_zi = new char[501];
        strcpy(this->descriere_zi,"");
    }

    void Setter_descriere_zi(char* descriere_zi)
    {
        strcat(this->descriere_zi,descriere_zi);
        strcat(this->descriere_zi,"\n");
    }


    void Setter_nr_zile_ocupate(int n=1)
    {
        nr_zile_ocupate+=n;
    }

    void Setter_zi_ocupata()
    {
        zi_ocupata = true;
    }
    //functii
    void Planificare_zi(int anul_dorit,int luna_dorita,list <Agenda>& zile_planificate)
    {
        an = anul_dorit;
        luna = luna_dorita;



        descriere_zi = new char[501];
        strcpy(descriere_zi,"");

        input[0] = 0; //goleste input-ul

        cout<<"Introduceti ziua pe care doriti sa o accesati: ";
        cin>>zi;


        Calendar c(anul_dorit,luna_dorita-1);
        while(zi > c.Getter_zile_in_luna(luna_dorita) || zi <= 0 || !cin)
        {
            cin.clear();
            cin.ignore(500,'\n');
            cout<<"Zi inexistenta"<<endl;
            cout<<"Introduceti ziua pe care doriti sa o accesati: ";
            cin>>zi;
        }




        list <Agenda> :: iterator i;
        for(i = zile_planificate.begin();i != zile_planificate.end(); ++i)
        {
            if(*this == *i)
            {
                zi_ocupata = true;
            }
        }


        if(zi_ocupata == true)
        {
            cout<<"Zi deja ocupata";
            zi_ocupata = false;
            return;
        }


        cout<<endl<<"Puteti scrie ce doriti: "<<endl;
        cout<<"Daca ati terminat, introduceti 'gata' "<<endl;


        cin.clear();
        cin.ignore(500,'\n');

        while(strcmp(input,"gata") != 0)
        {

            cin.get(input,500);

            if(strcmp(input,"gata") != 0)
            {
                strcat(descriere_zi,input);
                strcat(descriere_zi,"\n");
            }
            cin.clear();
            cin.ignore(500,'\n');

        }
        zile_planificate.push_back(*this);
        nr_zile_ocupate++;
    }

    void Planificare_zi_map(int anul_dorit,int luna_dorita,map <int,Agenda>& zile_planificate)
    {
        an = anul_dorit;
        luna = luna_dorita;



        descriere_zi = new char[501];
        strcpy(descriere_zi,"");

        input[0] = 0; //goleste input-ul

        cout<<"Introduceti ziua pe care doriti sa o accesati: ";
        cin>>zi;


        Calendar c(anul_dorit,luna_dorita-1);
        while(zi > c.Getter_zile_in_luna(luna_dorita) || zi <= 0 || !cin)
        {
            cin.clear();
            cin.ignore(500,'\n');
            cout<<"Zi inexistenta"<<endl;
            cout<<"Introduceti ziua pe care doriti sa o accesati: ";
            cin>>zi;
        }




        map <int,Agenda> :: iterator i;
        for(i = zile_planificate.begin();i != zile_planificate.end(); ++i)
        {
            if(*this == (*i).second)
            {
                zi_ocupata = true;
            }
        }


        if(zi_ocupata == true)
        {
            cout<<"Zi deja ocupata";
            zi_ocupata = false;
            return;
        }


        cout<<endl<<"Puteti scrie ce doriti: "<<endl;
        cout<<"Daca ati terminat, introduceti 'gata' "<<endl;


        cin.clear();
        cin.ignore(500,'\n');

        while(strcmp(input,"gata") != 0)
        {

            cin.get(input,500);

            if(strcmp(input,"gata") != 0)
            {
                strcat(descriere_zi,input);
                strcat(descriere_zi,"\n");
            }
            cin.clear();
            cin.ignore(500,'\n');

        }
        zile_planificate.insert(pair<int,Agenda>(nr_zile_ocupate+1,*this));
        nr_zile_ocupate++;
    }

    void Planificare_zi_set(int anul_dorit,int luna_dorita,set <Agenda>& zile_planificate)
    {
        an = anul_dorit;
        luna = luna_dorita;



        descriere_zi = new char[501];
        strcpy(descriere_zi,"");

        input[0] = 0; //goleste input-ul

        cout<<"Introduceti ziua pe care doriti sa o accesati: ";
        cin>>zi;


        Calendar c(anul_dorit,luna_dorita-1);
        while(zi > c.Getter_zile_in_luna(luna_dorita) || zi <= 0 || !cin)
        {
            cin.clear();
            cin.ignore(500,'\n');
            cout<<"Zi inexistenta"<<endl;
            cout<<"Introduceti ziua pe care doriti sa o accesati: ";
            cin>>zi;
        }




        set <Agenda> :: iterator i;
        for(i = zile_planificate.begin();i != zile_planificate.end(); ++i)
        {
            if(*this == *i)
            {
                zi_ocupata = true;
            }
        }


        if(zi_ocupata == true)
        {
            cout<<"Zi deja ocupata";
            zi_ocupata = false;
            return;
        }


        cout<<endl<<"Puteti scrie ce doriti: "<<endl;
        cout<<"Daca ati terminat, introduceti 'gata' "<<endl;


        cin.clear();
        cin.ignore(500,'\n');

        while(strcmp(input,"gata") != 0)
        {

            cin.get(input,500);

            if(strcmp(input,"gata") != 0)
            {
                strcat(descriere_zi,input);
                strcat(descriere_zi,"\n");
            }
            cin.clear();
            cin.ignore(500,'\n');

        }
        zile_planificate.insert(*this);
        nr_zile_ocupate++;
    }

    void Planificare_zi_vector(int anul_dorit,int luna_dorita,vector <Agenda>& zile_planificate)
    {
        an = anul_dorit;
        luna = luna_dorita;



        descriere_zi = new char[501];
        strcpy(descriere_zi,"");

        input[0] = 0; //goleste input-ul

        cout<<"Introduceti ziua pe care doriti sa o accesati: ";
        cin>>zi;


        Calendar c(anul_dorit,luna_dorita-1);
        while(zi > c.Getter_zile_in_luna(luna_dorita) || zi <= 0 || !cin)
        {
            cin.clear();
            cin.ignore(500,'\n');
            cout<<"Zi inexistenta"<<endl;
            cout<<"Introduceti ziua pe care doriti sa o accesati: ";
            cin>>zi;
        }




        vector <Agenda> :: iterator i;
        for(i = zile_planificate.begin();i != zile_planificate.end(); ++i)
        {
            if(*this == *i)
            {
                zi_ocupata = true;
            }
        }


        if(zi_ocupata == true)
        {
            cout<<"Zi deja ocupata";
            zi_ocupata = false;
            return;
        }


        cout<<endl<<"Puteti scrie ce doriti: "<<endl;
        cout<<"Daca ati terminat, introduceti 'gata' "<<endl;


        cin.clear();
        cin.ignore(500,'\n');

        while(strcmp(input,"gata") != 0)
        {

            cin.get(input,500);

            if(strcmp(input,"gata") != 0)
            {
                strcat(descriere_zi,input);
                strcat(descriere_zi,"\n");
            }
            cin.clear();
            cin.ignore(500,'\n');

        }
        zile_planificate.push_back(*this);
        nr_zile_ocupate++;
    }

    void Help()override
    {
        cout<<"Clasa Agenda se ocupa de:\nProgramarea unei zile dintr-un calendar\nSetarea unei descrieri ale acelei zile ocupate";
    }
    void NumeClasa()override
    {
        cout<<"\nAgenda";
    }

    //operatori
    bool operator==(Agenda& zi_aleasa)
    {
        if(zi == zi_aleasa.zi && luna == zi_aleasa.luna && an == zi_aleasa.an)
        {
            return true;
        }else
            return false;
    };
    Agenda& operator=(Agenda& zi_aleasa)
    {
        an = zi_aleasa.an;
        luna = zi_aleasa.luna;
        zi = zi_aleasa.zi;

        strcpy(input,zi_aleasa.input);

        zi_ocupata = zi_aleasa.zi_ocupata;

        descriere_zi = new char[strlen(zi_aleasa.descriere_zi)];
        strcpy(descriere_zi,zi_aleasa.descriere_zi);

        return *this;

    }
    int operator[](int index)
    {
        if(index<300 && index>=0)
            return this->input[index];
        else
        {
                cout<<"Index invalid";
                return -1;
        }
    }
    Agenda& operator++(int valoare)
    {
        valoare = 1;
        zi += valoare;

        return *this;
    }
    Agenda& operator++()
    {
        int valoare = 1;
        zi += valoare;

        return *this;
    }
    Agenda& operator+(int valoare)
    {
        Calendar c(an,luna);
        if(zi + valoare >c.Getter_zile_in_luna(luna))
        {
            zi = zi + valoare - c.Getter_zile_in_luna(luna);
        }else
        {
            zi += valoare;
        }


        return *this;
    }
    Agenda& operator-(int valoare)
    {
        Calendar c(an,luna);
        if(zi - valoare <= 0)
        {
            zi = c.Getter_zile_in_luna(luna) - (valoare - zi);
        }else
        {
            zi -= valoare;
        }

        return *this;
    }
    operator int() const
    {
        return zi*1000000+luna*10000+an;
    }
    bool operator >=(Agenda& zi_aleasa)
    {
        if(zi >= zi_aleasa.zi || luna >= zi_aleasa.luna || an >= zi_aleasa.an)
        {
            return true;
        }else
            return false;
    }

    friend ostream& operator<<(ostream& os, const Agenda& ag);
    friend istream& operator>>(istream& is, const Agenda& ag);

    //destructor
    ~Agenda()
    {

    };
};

istream& operator>>(istream& is,Agenda& ag)
{
        int an,luna,zi;
        char input[500];
        cout<<"Introduce-ti anul, luna si ziua dorite(ex. 2020 2 1):";
        is>>an>>luna>>zi;



        while(luna < 1 || luna >12 || an < 1 || !is)
        {
            cout<<endl<<"!!!Data a fost introdusa gresit!!!"<<endl;
            is.clear();
            is.ignore(100,'\n');
            cout<<endl<<"Introduceti o data valida(ex 2020 2 1): ";
            is>>an>>luna>>zi;
        }

        ag.Setter_an(an);
        ag.Setter_luna(luna-1);

        Calendar c(ag.Getter_an(),ag.Getter_luna());

        while(zi > c.Getter_zile_in_luna(ag.Getter_luna()) || zi <= 0 || !is)
        {
            cout<<endl<<"!!!Zi inexistenta!!!"<<endl;
            is.clear();
            is.ignore(100,'\n');
            cout<<endl<<"Introduceti o zi valida: ";
            is>>zi;
        }

        ag.Setter_zi(zi);

        cout<<endl<<"Puteti scrie ce doriti: "<<endl;
        cout<<"Daca ati terminat, introduceti 'gata' "<<endl;


        ag.Setter_descriere_zi();

        input[0] = 0;

        is.clear();
        is.ignore(500,'\n');

        while(strcmp(input,"gata") != 0)
        {

            is.get(input,500);


            if(strcmp(input,"gata") != 0)
            {
                ag.Setter_descriere_zi(input);
            }
            is.clear();
            is.ignore(500,'\n');

        }
        ag.Setter_input(" ");
        ag.Setter_zi_ocupata();
        ag.Setter_nr_zile_ocupate();

        return is;
}
ostream& operator<<(ostream& os, const Agenda& ag)
{
    os <<endl<<"Anul: "<< ag.an <<" Luna: "<< ag.luna + 1<<" Ziua: "<<ag.zi<<endl<<"Descriere zi: "<<endl<<ag.descriere_zi<<endl;
    return os;
}

int Agenda::nr_zile_ocupate;

class AgendaLista ///Relatie de tipul HAS A
{

public:
    Agenda a;
    list <Agenda> lista;
    map <int,Agenda> lista1;
    set <Agenda> lista2;
    vector <Agenda> lista3;

    Agenda get_agenda()
    {
        return a;
    }

    list<Agenda> get_lista()
    {
        return lista;
    }
};


class Sarbatori: public Agenda ///Relatie de tipul IS A (mosteneste si AjutorClase, deoarece Agenda mosteneste AjutorClase)
{

char* descriere_sarbatoare[7] = {"Pastele catolic","Sf. Andrei","Sf.Nicolae","Martisorul","Marea unire","Mica unire","Craciunul"};
list <Agenda> lista_sarbatori;

public:
    //functii
    list<Agenda> Setare_sarbatori()
    {
        int an;
        cout<<"Introduceti anul pentru care vreti sa vizualizati sarbatorile(0 pentru anul acesta): ";
        cin>>an;
        if(an != 0)
            this->Setter_an(an);

        else
        {
            time_t now = time(0);
            char* data = ctime(&now);
            an = 0;
            int j=1000;
            for(int i= strlen(data)-5;i<=strlen(data)-1;i++)
            {
                an += (data[i] - '0')*j;
                j = j / 10;
            }
            this->Setter_an(an);

        }

        this->Setter_nr_zile_ocupate(7);


        Setter_luna(11);
        Setter_zi(25);
        Setter_descriere_zi();
        Setter_descriere_zi(descriere_sarbatoare[6]);
        lista_sarbatori.push_back(*this);

        Setter_luna(10);
        Setter_zi(30);
        Setter_descriere_zi();
        Setter_descriere_zi(descriere_sarbatoare[1]);
        lista_sarbatori.push_back(*this);

        Setter_luna(11);
        Setter_zi(6);
        Setter_descriere_zi();
        Setter_descriere_zi(descriere_sarbatoare[2]);
        lista_sarbatori.push_back(*this);

        Setter_luna(2);
        Setter_zi(1);
        Setter_descriere_zi();
        Setter_descriere_zi(descriere_sarbatoare[3]);
        lista_sarbatori.push_back(*this);

        Setter_luna(11);
        Setter_zi(1);
        Setter_descriere_zi();
        Setter_descriere_zi(descriere_sarbatoare[4]);
        lista_sarbatori.push_back(*this);

        Setter_luna(0);
        Setter_zi(24);
        Setter_descriere_zi();
        Setter_descriere_zi(descriere_sarbatoare[5]);
        lista_sarbatori.push_back(*this);

        Setter_luna(3);
        Setter_zi(gaussEaster(this->Getter_an()));
        Setter_descriere_zi();
        Setter_descriere_zi(descriere_sarbatoare[0]);
        lista_sarbatori.push_back(*this);




    return lista_sarbatori;

    }

    int gaussEaster(int Y) ///cod de a calcula cand pica pastele preluat de pe https://www.geeksforgeeks.org/how-to-calculate-the-easter-date-for-a-given-year-using-gauss-algorithm/
    {
        float A, B, C, P, Q, M, N, D, E;

    // All calculations done
    // on the basis of
    // Gauss Easter Algorithm
        A = Y % 19;
        B = Y % 4;
        C = Y % 7;
        P = (float)floor(Y / 100);
        Q = (float)floor((13 + 8 * P) / 25);
        M = (int)(15 - Q + P - P / 4) % 30;
        N = (int)(4 + P - P / 4) % 7;
        D = (int)(19 * A + M) % 30;
        E = (int)(2 * B + 4 * C + 6 * D + N) % 7;
        int days = (int)(22 + D + E);

    // A corner case,
    // when D is 29
        if ((D == 29) && (E == 6))
            {
                //cout << Y << "-04-19";
                return 19;
            }
    // Another corner case,
    // when D is 28
        else if ((D == 28) && (E == 6))
            {
                //cout << Y << "-04-18";
                return 18;
            }
        else
        {
        // If days > 31, move to April
        // April = 4th Month
            if (days > 31)
            {
                //cout << Y << "-04-"<< (days - 31);
                return days - 31;
            }
            else
            {
            // Otherwise, stay on March
            // March = 3rd Month
                //cout << Y << "-03-"<< days;
                return days;
            }
        }
}

    void Help()override
    {
        cout<<"Clasa Sarbatori se ocupa de:\nCalcului zilei de paste Catolic al unui an\nGasirea zilelor de sarbatoare romanesti ale oricarui an";
    }
    void NumeClasa()override
    {
        cout<<"\nSarbatori";
    }
};


class Afisaj:public AjutorClase
{
private:
    char* bun_venit;
    static int afisaje_active;

public:
    //constructor fara parametrii
    Afisaj()
    {
        bun_venit = "===Planificator personal===\n                          Meniu principal\n\nComenzi : \nPentru a viziona calendarul, introduceti 'calendar' \nPentru a viziona zilele planificate, introduceti 'ocupat' \nPentru a planifica o zi specifica, introduceti 'plan'(acest lucru se poate face si din calendar) \nPentru a viziona data si timpul curent, introduceti 'data' \nPentru a vizualiza zilele de sarbatoare, introduceti 'sarbatori' \nPentru a opri programul, introduceti 'stop' \nPentru a salva modificarile, introduceti 'salveaza' \nComanda: ";

        afisaje_active=+1;

    }
    //constructor cu parametrii 1
    Afisaj(char* bun_venit)
    {
        this->bun_venit = new char[501];
        strcpy(this->bun_venit,bun_venit);
        afisaje_active++;
    }
    //constructor cu parametrii 2
    Afisaj(char* bun_venit,int incrementare)
    {
        this->bun_venit = new char[501];
        strcpy(this->bun_venit,bun_venit);
        afisaje_active += incrementare;
    }
    //constructor de copiere
    Afisaj(const Afisaj& af)
    {
        this->bun_venit = new char[501];
        strcpy(this->bun_venit,af.bun_venit);
        this->afisaje_active += 1;
    }
    //setteri
    void set_bun_venit(char* bun_venit)
    {
        if(this->bun_venit != NULL)
            delete[] this->bun_venit;
        this->bun_venit = new char[501];
        strcpy(this->bun_venit,bun_venit);

    }

    void set_afisaje_active()
    {
        afisaje_active += 1;
    }
    //getteri
    char* get_bun_venit()
    {
        return bun_venit;
    }

    static int get_afisaje_active()
    {
        return afisaje_active;
    }

    //functii
    void Afisaj_Calendar(Calendar &calendar,list<Agenda> zile_planificate)
    {
        cout << string( 50, '\n' );
        cout<<calendar;
        int indentari[] = {7,8,11,6,9,10,1};
        int index_indentari = 0;

        bool zi_ocupata = false;

        int cod;

        cod = calendar.Getter_Setter_Codul_zilei();


        cout<<endl;
        cout<<"==="<<calendar.Getter_luni(calendar.Getter_luna())<<"==="<<endl;
        cout<<"Luni   Marti   Miercuri   Joi   Vineri   Sambata   Duminica"<<endl;

        if(cod != 0)
        {
            for (int zi = 1; zi <= cod; zi++ )
            {

                cout<<" "<<setw(indentari[index_indentari]);
                index_indentari++;
            }
        }



        for(int zi=1;zi <= calendar.Getter_zile_in_luna(calendar.Getter_luna());zi++)
        {
            if(zi!=9)
            {
                list <Agenda> :: iterator it;
                for(it = zile_planificate.begin();it != zile_planificate.end(); ++it)
                {

                    if((*it).Getter_an() == calendar.Getter_an() && (*it).Getter_luna() == calendar.Getter_luna() && (*it).Getter_zi() == zi)
                    {
                        cout<<"X"<<setw(indentari[index_indentari]);
                        zi_ocupata = true;
                    }
                }

                if(zi_ocupata == false)
                {
                    cout<<zi<<setw(indentari[index_indentari]);
                }

                zi_ocupata = false;

            }
            else
            {
                list <Agenda> :: iterator it;
                for(it = zile_planificate.begin();it != zile_planificate.end(); ++it)
                {

                    if((*it).Getter_an() == calendar.Getter_an() && (*it).Getter_luna() == calendar.Getter_luna() && (*it).Getter_zi() == zi)
                    {
                        cout<<"X"<<setw(indentari[index_indentari]+1);
                        zi_ocupata = true;
                    }
                }

                if(zi_ocupata == false)
                {
                    cout<<zi<<setw(indentari[index_indentari]+1);
                }

                zi_ocupata = false;
            }

            if(index_indentari > 5)
            {
                index_indentari = 0;
            }else
                {
                    index_indentari++;
                }

            if((zi + cod) % 7 == 0)
            {
                cout<<endl;
            }


        }
        cout<<endl<<endl;
    }

    void Afisaj_Meniu_Calendar()
    {
        cout<<"Daca doriti sa planificati o zi, introduceti 'plan' "<<endl<<endl;
        cout<<"Pentru a schimba pagina, introduceti '<' sau '>' "<<endl<<endl;
        cout<<"Pentru a vizualiza zodia dintr-o zi specifica a lunei curente, introduceti 'zodie' "<<endl<<endl;
        cout<<"Pentru a va intoarce la meniul principal, introduceti 'inapoi' "<<endl<<endl;
    }

    void Afisaj_Zile_Ocupate(list <Agenda> zile_planificate,Agenda agenda)
    {
        cout << "Numarul de zile ocupate: " << agenda.Getter_nr_zile_ocupate()<<endl;
        list <Agenda> :: iterator it;
        for(it = zile_planificate.begin();it != zile_planificate.end(); ++it)
        {

            cout<<'\t'<<*it;
        }
    }

    void Afisaj_Zodie(CalendarZodiac cz)
    {
        int zi;
        cout<<"Introduceti ziua dorita: ";
        cin>>zi;
        while(zi > cz.Getter_zile_in_luna(cz.Getter_luna()) || zi <= 0 || !cin)
        {
            cout<<endl<<"!!!Zi inexistenta!!!"<<endl;
            cin.clear();
            cin.ignore(100,'\n');
            cout<<endl<<"Introduceti o zi valida: ";
            cin>>zi;
        }

        cout<<cz.Afla_zodie(zi)<<endl;
        cout<<"Comanda: ";
    }

    void Afisaj_Sarbatori(list<Agenda> lista_sarbatori)
    {
        for(list<Agenda>::iterator i = lista_sarbatori.begin();i!=lista_sarbatori.end();++i)
        {
            cout<<*i;
        }
    }
    void Afisaj_Zile_Ocupate_map(map<int,Agenda> lista_sarbatori)
    {
        for(map<int,Agenda>::iterator i = lista_sarbatori.begin();i!=lista_sarbatori.end();++i)
        {
            cout<<(*i).first;
            cout<<(*i).second;
        }
    }
    void Afisaj_Zile_Ocupate_set(set<Agenda> lista_sarbatori)
    {
        for(set<Agenda>::iterator i = lista_sarbatori.begin();i!=lista_sarbatori.end();++i)
        {
            cout<<*i;
        }
    }
    void Afisaj_Zile_Ocupate_vector(vector<Agenda> lista_sarbatori)
    {
        for(vector<Agenda>::iterator i = lista_sarbatori.begin();i!=lista_sarbatori.end();++i)
        {
            cout<<*i;
        }
    }

    void Help()override
    {
        cout<<"Clasa Afisaj se ocupa de:\nAfisarea diverselor date pe ecran\n";
    }
    void NumeClasa()override
    {
        cout<<"Afisaj";
    }


    //operatori
    Afisaj& operator=(Afisaj& af)
    {
        if(this->bun_venit != NULL)
            delete [] this->bun_venit;

        this->bun_venit = new char[501];
        strcpy(this->bun_venit,af.bun_venit);
        this->afisaje_active += 1;

        return *this;
    }

    friend ostream& operator>>(ostream& os,Afisaj& af);
    friend istream& operator<<(istream& is,Afisaj& af);
    //destructor
    ~Afisaj()
    {
        /*if(bun_venit != NULL)
            delete [] bun_venit;*/
    }
};
int Afisaj::afisaje_active = 0;

ostream& operator<<(ostream& os,Afisaj& af)
{
    os << string( 50, '\n' );
    os<<"Numar afisaje: "<<af.get_afisaje_active()<<endl<<endl;
    os<<setw(20)<<" ";
    os<<af.get_bun_venit();

    return os;
}
istream& operator>>(istream& is,Afisaj& af)
{
    char* bun_venit;
    bun_venit = new char[501];
    is.get(bun_venit,501);
    af.set_bun_venit(bun_venit);
    af.set_afisaje_active();
    return is;
}


class Comenzi:public AjutorClase
{
private:
    const char* comenzi[6];
    bool activ;
protected:
    char* comanda;


public:
    //constructor fara parametrii
    Comenzi():comenzi{"calendar","stop","ocupat","plan","data","salveaza"}
    {
        comanda = " ";
        activ = true;
    }
    //constructor cu parametrii 1
    Comenzi(char* comanda):comenzi{"calendar","stop","ocupat","plan","data","salveaza"}
    {
        this->comanda = new char[strlen(comanda)+1];
        strcpy(this->comanda,comanda);
        activ = true;
        cout<<this->comanda;
    }
    //constructor cu parametrii 2
    Comenzi(char* comanda,bool activ):comenzi{"calendar","stop","ocupat","plan","data","salveaza"}
    {
        this->comanda = new char[strlen(comanda)+1];
        strcpy(this->comanda,comanda);
        this->activ = activ;
        cout<<this->comanda;
        cout<<this->activ;

    }
    //Constructor de copiere
    Comenzi(const Comenzi& co)
    {
        for(int i = 0;i<5;i++)
        {
            comenzi[i] = co.comenzi[i];
        }
        comanda = new char[strlen(co.comanda)+1];
        strcpy(comanda,co.comanda);

        activ = co.activ;

    }
    //getteri
    const char* get_comenzi(int indice)
    {
        return comenzi[indice];
    }

    char* get_comanda()
    {
        return comanda;
    }

    bool get_activ()
    {
        return activ;
    }
    //setteri
    void set_comenzi(int indice,const char * comanda)
    {
        comenzi[indice] = comanda;
    }
    void set_comanda(char * comanda)
    {
        if(this->comanda != NULL)
        {
            delete[] this->comanda;
        }
        this->comanda = new char[strlen(comanda)+1];
        strcpy(this->comanda,comanda);
    }
    void set_activ(bool activ)
    {
        this->activ = activ;
    }
    //functii
    bool Introducere_an(Calendar &calendar)
    {
        cin>>calendar;
        return 1;
    }

    void Mutare_pagina_calendar(Afisaj &afisaj,Calendar &calendar,bool directie,list<Agenda> zile_planificate)
    {
        if(directie)
        {
            if(calendar.Getter_luna() == 11 && directie == true)
                {
                    calendar.Setter_luna(0);
                }
                else
                {
                    calendar.Setter_luna(calendar.Getter_luna() + 1);
                }

        }else
        {
            if(calendar.Getter_luna() == 0 && directie == false)
                {
                    calendar.Setter_luna(11);
                }
                else
                {
                    calendar.Setter_luna(calendar.Getter_luna() - 1);
                }
        }
        afisaj.Afisaj_Calendar(calendar,zile_planificate);

    }

    void Verifica_comanda(string &comanda)
    {
        while((comanda != "calendar" && comanda != "stop" && comanda != "ocupat"&& comanda != "plan"&& comanda != "data"&& comanda != "sarbatori"&& comanda != "salveaza") || !cin)
        {
            cout<<"!!!Comanda incorecta!!!"<<endl;
            cin.clear();
            cin.ignore(100,'\n');
            cout<<endl<<"Comanda :";
            cin>>comanda;
        }
    }

    void Help()override
    {
        cout<<"Clasa Comenzi se ocupa de:\nVerificarea comenzilor de a fi introduse corect\nActiuni diverse pentru a folosi aplicatia";
    }
    void NumeClasa()override
    {
        cout<<"\nComenzi";
    }

    //operatori
    Comenzi& operator=(Comenzi& co)
    {
        for(int i = 0;i<5;i++)
        {
            comenzi[i] = co.comenzi[i];
        }

        if(comanda != NULL)
        {
            delete[] comanda;
        }


        comanda = new char[strlen(co.comanda)+1];
        strcpy(comanda,co.comanda);

        activ = co.activ;

        return *this;
    }
    friend ostream& operator>>(ostream& os,Comenzi& co);
    friend istream& operator<<(istream& is,Comenzi& co);

    //destructor
    ~Comenzi()
    {

    }
};
ostream& operator<<(ostream& os,Comenzi& co)
{
        for(int i = 0; i < 5;i++)
        {
            os<<co.get_comenzi(i)<<endl;
        }
        os<<co.get_comanda();
        os<<co.get_activ();
    return os;
}
istream& operator>>(istream& is,Comenzi& co)
{
    const char* comenzi[5] = {"calendar","stop","ocupat","plan","data"};
    char* comanda;

    cout<<"Comanda: ";
    comanda = new char[100];
    is.get(comanda,100);
    cout<<"1";
    for(int i = 0;i< 5;i++)
        {
            co.set_comenzi(i,comenzi[i]);
        }
    cout<<"2";

        co.set_comanda(comanda);

    cout<<"3";
    co.set_activ(true);
    cout<<"4";
    return is;
}


class ManagerSalvare
{
    fstream save;

    int an, luna, zi;
    char* descriere_zi;
    char input[500];
    bool zi_ocupata;
    static int nr_zile_ocupate;

public:
    void save_zile_ocupate(list <Agenda>& lista)
    {
        try
        {
            save.open("SaveFile.txt",ios::out | ios::trunc);
            if(!save.is_open())
            {
                throw save.is_open();
            }

            list <Agenda>::iterator i;

            for(i = lista.begin();i != lista.end();++i)
            {

                save<<i->Getter_an()<<endl;
                save<<i->Getter_luna()<<endl;
                save<<i->Getter_zi()<<endl;
                save<<i->Getter_descriere_zi();
                save<<"end"<<endl;
            }

            save.close();
            cout<<"Salvare cu succes";
        }
        catch(bool)
        {
            cout<<"Deschidere fisier esuata";
            save.close();
        }

    }

    void load_zile_ocupate(list<Agenda>& lista)
    {
        try
        {
            save.open("SaveFile.txt",ios::in);
            string temp;
            int linie = 1;
            int an,luna,zi;
            string descriere;
            bool checked = false;

            while(getline(save,temp))
            {
                if(temp == "" && checked == false)
                {
                    throw temp;
                }

                checked = true;

                if(linie == 1)
                    {
                        an = stoi(temp);
                        cout<<an<<endl;
                    }
                if(linie == 2)
                    {
                        luna = stoi(temp);
                        cout<<luna<<endl;
                    }
                if(linie == 3)
                    {
                        zi = stoi(temp);
                        cout<<zi<<endl;
                    }
                if(linie >= 4 && temp != "end")
                    {
                        descriere+= temp + "\n";
                        cout<<descriere<<endl;
                    }
                if(temp == "end")
                {
                    Agenda ag(an,luna,zi,const_cast<char*>(descriere.c_str()));///.c_str() returneaza un const char*, folosesc const_cast<> ca sa scap de atributul const
                    lista.push_back(ag);
                    descriere = "\0";
                    linie = 0;
                }

                linie++;


            }
            save.close();
        }
        catch(string)
        {
            cout<<"Fisier SaveFile.txt gol";
            save.close();
        }


    }
};



int main()
{
    /*system("Color 1F");*////schimb de culoare al consolei
    Calendar calendar;
    Afisaj afisaj;
    Comenzi comenzi;
    Agenda agenda;
    AgendaLista zile_planificate;
    ManagerSalvare salvare;



    /*Sarbatori a;
    CalendarZodiac b(calendar);

    calendar.Help();
    calendar.NumeClasa();
    cout<<"\n\n";
    agenda.Help();
    agenda.NumeClasa();
    cout<<"\n\n";
    a.Help();
    a.NumeClasa();
    cout<<"\n\n";
    afisaj.Help();
    afisaj.NumeClasa();
    cout<<"\n\n";
    comenzi.Help();
    comenzi.NumeClasa();
    cout<<"\n\n";
    b.Help();
    b.NumeClasa();*/ ///exemplificarea conceptului de virtualizare oferit de clasa AjutorClase

    /*Comenzi b;
    cin>>b;
    cout<<b;*/ ///test >> pentru comenzi

    /*Comenzi s;
    s = comenzi;*/ ///test =
    /*Comenzi c(comenzi);*/ ///test constructor copiere
    /*char* comand = "da";
    Comenzi a(comand);
    Comenzi b(comand,true);*/ /// test constructor cu parametrii 1 / test constructor cu parametrii 2

    /*cin>>afisaj;*/ ///test >>

    /*Afisaj a(afisaj);*/ /// test constructor de copiere
    /*char* bun_venit = {"===Planificator personal===\n   Meniu principal\n\nComenzi : \n Pentru a viziona calendarul, introduceti 'calendar' \n Pentru a viziona calendarul, introduceti 'calendar' \n Pentru a planifica o zi specifica, introduceti 'plan'(acest lucru se poate face si din calendar) \n Pentru a viziona data si timpul curent, introduceti 'data' \n Pentru a opri programul, introduceti 'stop' \n Comanda: "};
    Afisaj afisaj(bun_venit,1);*/ /// test constructor cu param 1
    /*char* bun_venit = {"===Planificator personal===\n   Meniu principal\n\nComenzi : \n Pentru a viziona calendarul, introduceti 'calendar' \n Pentru a viziona calendarul, introduceti 'calendar' \n Pentru a planifica o zi specifica, introduceti 'plan'(acest lucru se poate face si din calendar) \n Pentru a viziona data si timpul curent, introduceti 'data' \n Pentru a opri programul, introduceti 'stop' \n Comanda: "};
    Afisaj afisaj1(bun_venit,1);*/ /// test constructor cu param 2
   /*Afisaj a = afisaj;*/


    /*Calendar c(calendar);*/   ///test constructor copiere
    /*Calendar c2(2020,0);*/ ///test constructor cu param 1
    /*int zile[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    Calendar c2(2020,0,6,true,zile);*////test constructor cu param 2
    /*Calendar c2;
    c2= calendar;
    cout<<c2;*/ ///test operator = pentru calendar
    /*cout<<calendar[2];*/ ///test [] pentru calendar
    /*++calendar;
    cout<<calendar;*/ ///test ++ pentru calendar
    /*calendar-1;
    cout<<calendar;*/ ///test + si - pentru calendar
    /*cout<<int(calendar);*/ ///test operator cast int
    /*Calendar c(2021,1);
    if(c==calendar)
        cout<<"Da";
    else
        cout<<"Nu";*/ ///test operator >= si == pentru calendar

    /*Agenda c(2020,2,1,"Evenimentul zilei");
    cout<<c;*/ ///test constructor cu param 1
    /*char input[500] = {'a','b'};
    Agenda c2(2020,2,1,"Evenimentul zilei",true,input,1);
    cout<<c2;*/ ///test constructor cu param 2
    /*agenda++;
    cout<<agenda;*/ ///test ++ pentru agenda
    /*agenda-1;
    cout<<agenda;*/ ///test operator + si -
    /*cout<<int(agenda);*/ /// test operator cast int pentru agenda


    string comanda = " ";

    salvare.load_zile_ocupate(zile_planificate.lista);

    while(comanda != "stop")
    {
        cout<<afisaj;

        cin>>comanda;

        cout<<endl;

        comenzi.Verifica_comanda(comanda);

        if(comanda == "calendar")
        {
            if(comenzi.Introducere_an(calendar))
            {
                afisaj.Afisaj_Calendar(calendar,zile_planificate.lista);

                afisaj.Afisaj_Meniu_Calendar();

                while(comanda != "inapoi")
                {
                    cin>>comanda;

                    if(comanda == "plan")
                    {
                        agenda.Planificare_zi(calendar.Getter_an(),calendar.Getter_luna(),zile_planificate.lista); /// folosind list
                        /*agenda.Planificare_zi_map(calendar.Getter_an(),calendar.Getter_luna(),zile_planificate.lista1);*/ /// folosind map
                        /*agenda.Planificare_zi_set(calendar.Getter_an(),calendar.Getter_luna(),zile_planificate.lista2);*/ ///folosind set
                        /*agenda.Planificare_zi_vector(calendar.Getter_an(),calendar.Getter_luna(),zile_planificate.lista3);*/ ///folosind vector

                        afisaj.Afisaj_Calendar(calendar,zile_planificate.lista);

                        afisaj.Afisaj_Meniu_Calendar();
                    }
                    if(comanda == "<")
                    {
                        comenzi.Mutare_pagina_calendar(afisaj,calendar,false,zile_planificate.lista);

                        afisaj.Afisaj_Meniu_Calendar();
                    }
                    if(comanda == ">")
                    {
                        comenzi.Mutare_pagina_calendar(afisaj,calendar,true,zile_planificate.lista);

                        afisaj.Afisaj_Meniu_Calendar();
                    }
                    if(comanda == "zodie")
                    {
                        CalendarZodiac zodiac(calendar);
                        afisaj.Afisaj_Zodie(zodiac);

                    }
                }
                cout << string( 50, '\n' );
            }
        }

        if(comanda == "ocupat")
        {
            afisaj.Afisaj_Zile_Ocupate(zile_planificate.lista,agenda); /// folosind list
            /*afisaj.Afisaj_Zile_Ocupate_map(zile_planificate.lista1);*/ /// folosind map
            /*afisaj.Afisaj_Zile_Ocupate_set(zile_planificate.lista2);*/ ///folosind set
            /*afisaj.Afisaj_Zile_Ocupate_vector(zile_planificate.lista3);*/ ///folosind vector
            while(comanda != "inapoi")
            {
                cout<<endl<<"Pentru a va intoarce la meniul principal, introduceti 'inapoi' "<<endl;
                cin>>comanda;
            }
        }

        if(comanda == "data")
        {
            calendar.Data_curenta();
            while(comanda != "inapoi")
            {
                cout<<endl<<"Pentru a va intoarce la meniul principal, introduceti 'inapoi' "<<endl;
                cin>>comanda;
            }
        }

        if(comanda == "plan")
        {
            while(comanda != "inapoi")
            {

                list <Agenda> :: iterator i;

                bool introdus = false;

                cin>>zile_planificate.a;;

                for(i = zile_planificate.lista.begin();i != zile_planificate.lista.end(); ++i)
                {
                    if(zile_planificate.a == *i)
                    {
                        cout<<"Data introdusa a fost deja planificata";
                        introdus = true;
                    }
                }

                if(introdus == false)
                {
                    zile_planificate.lista.push_back(zile_planificate.a); /// folosind list
                    /*zile_planificate.lista1.insert(pair<int,Agenda>(zile_planificate.a.Getter_nr_zile_ocupate()+1,zile_planificate.a));*/ /// folosind map
                    /*zile_planificate.lista2.insert(zile_planificate.a);*/ ///folosind set
                    /*zile_planificate.lista3.push_back(zile_planificate.a);*/ ///folosind vector
                }
                cout<<endl<<"Introduceti alta data folosind comanda 'plan' sau intoarceti-va inapoi folosind 'inapoi' "<<endl;
                cin>>comanda;
            }
        }

        if(comanda == "sarbatori")
        {
            Sarbatori sarbatori;
            afisaj.Afisaj_Sarbatori(sarbatori.Setare_sarbatori());
            while(comanda != "inapoi")
            {
                cout<<endl<<"Pentru a va intoarce la meniul principal, introduceti 'inapoi' "<<endl;
                cin>>comanda;
            }
        }
        if(comanda == "salveaza")
        {
            salvare.save_zile_ocupate(zile_planificate.lista);
        }

    }

    return 0;
}
