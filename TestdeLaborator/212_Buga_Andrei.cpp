/*Buga Andrei 212
GNU GCC Compiler C++11 ISO C++ language standard
EDUARD GABRIEL SZMETEANCA*/

#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;


class Vaccin
{
private:
    int pret,tempDepozitare;
    string ingrediente;
    string numeProducator;

public:

    virtual void afisareSchemaVaccinare()
    {

    }

    string get_numeprod()
    {
        return numeProducator;
    }

    friend istream& operator>> (istream& in, Vaccin& c)
    {
        cout<<"Pret(ex. 300): ";
        in>>c.pret;
        cout<<"Temperatura depozitare(ex. 30): ";
        in>>c.tempDepozitare;
        cout<<"Ingrediente: ";
        in>>c.ingrediente;
        cout<<"Nume producator: ";
        in>>c.numeProducator;

        return in;
    }
    friend ostream& operator<< (ostream& out, Vaccin& c)
    {
        out<<endl<<"Pret: ";
        out<<c.pret;
        out<<endl<<"Temperatura depozitare: ";
        out<<c.tempDepozitare;
        out<<endl<<"Ingrediente: ";
        out<<c.ingrediente;
        out<<endl<<"Nume producator: ";
        out<<c.numeProducator;


        return out;
    }

    ~Vaccin()
    {

    }
};



class AntiGripal: public Vaccin
{
private:
    string tulpini; //A-H1N1, A-H3N2, A-California
    bool respectaOMS;

public:

    void afisareSchemaVaccinare() override
    {
        cout<<endl<<"Metoda vaccinare AntiGripal"<<endl;
        cout<<"Se administreaza la adulti o doza de 0.5 ml, iar la copii si adolescenti o doza de 0.3 ml, repetandu-se din 2 in 2 ani"<<endl;

    }

    friend istream& operator>> (istream& in, AntiGripal& c)
    {
        cout<<"Vaccin Antigripal"<<endl;
        in>>(Vaccin&)c;
        cout<<"Tulpini(ex. A-H1N1,A-H3N2,A-California): ";
        in>>c.tulpini;
        cout<<"Respecta OMS(1 pentru da ,0 pentru nu): ";
        in>>c.respectaOMS;

        return in;
    }
    friend ostream& operator<< (ostream& out, AntiGripal& c)
    {
        out<<endl<<"Vaccin Antigripal"<<endl;
        out<<(Vaccin&)c;
        out<<endl<<"Tulpini(ex. A-H1N1,A-H3N2,A-California): ";
        out<<c.tulpini;
        out<<endl<<"Respecta OMS(1 pentru da ,0 pentru nu): ";
        out<<c.respectaOMS;


        return out;
    }

    ~AntiGripal()
    {

    }
};



class SarsCov2 : public  Vaccin
{
private:
    string reactiiAdverse; // (durere de cap, stare de voma,ameteala, etc.)
    int rataEficienta;
    string medicamenteContra;//(pe 6 luni)

public:
    void afisareSchemaVaccinare() override
    {
        cout<<endl<<"Metoda vaccinare SarsCov2"<<endl;
        cout<<"Se administreaza persoanelor cu varsta de peste 16 ani, 2 doze la o perioada de 21 zile"<<endl;

    }
    friend istream& operator>> (istream& in, SarsCov2& c)
    {
        cout<<"Vaccin SarsCov2"<<endl;
        in>>(Vaccin&)c;
        cout<<"Reactii adverse(ex: durere de cap, stare de voma,ameteala, etc.): ";
        in>>c.reactiiAdverse;
        cout<<"Rata eficienta: ";
        in>>c.rataEficienta;
        cout<<"Medicamente contraindicate: ";
        in>>c.medicamenteContra;


        return in;
    }
    friend ostream& operator<< (ostream& out, SarsCov2& c)
    {
        out<<endl<<"Vaccin SarsCov2"<<endl;
        out<<(Vaccin&)c;
        out<<endl<<"Reactii adverse(ex: durere de cap, stare de voma,ameteala, etc.): ";
        out<<c.reactiiAdverse;
        out<<endl<<"Rata eficienta: ";
        out<<c.rataEficienta;
        out<<endl<<"Medicamente contraindicate: ";
        out<<c.medicamenteContra;

        return out;
    }

    ~SarsCov2()
    {

    }
};



class Hepatita: public Vaccin
{
private:
    char tipHepatita; //A,B,C
    string modVaccinare; //(intramuscular, subcutanat si intradermic)

public:

    void afisareSchemaVaccinare() override
    {
        cout<<endl<<"Metoda vaccinare AntiHepatic"<<endl;
        cout<<"Antihepatita A si B, la copii cu varsta mai mica de 1 an se adminstreaza 2 injectari la un interval de o luna, a treia injectare dupa 6 luni de la prima administrare,\nla adulti";
        cout<<"conform schemei de imunizare recomandata de medic(la fel hep C)"<<endl;
    }

    friend istream& operator>> (istream& in, Hepatita& c)
    {
        cout<<"Vaccin AntiHepatic"<<endl;
        in>>(Vaccin&)c;
        cout<<"Tip Hepatita(ex. A sau B sau C): ";
        in>>c.tipHepatita;
        cout<<"Mod vaccinare(ex. intramuscular, subcutanat si intradermic): ";
        in>>c.modVaccinare;

        return in;
    }
    friend ostream& operator<< (ostream& out, Hepatita& c)
    {
        out<<endl<<"Vaccin AntiHepatic"<<endl;
        out<<(Vaccin&)c;
        out<<endl<<"Tip Hepatita(ex. A sau B sau C): ";
        out<<c.tipHepatita;
        out<<endl<<"Mod vaccinare(ex. intramuscular, subcutanat si intradermic): ";
        out<<c.modVaccinare;


        return out;
    }

    ~Hepatita()
    {

    }
};

class Comanda
{
private:
    int id;
    string data;
    string numeClient;
    string numeVaccin;
    int doze;
public:
    Comanda()
    {
        id = 0;
        data = "necunoscut";
        numeClient = "necunoscut";
        numeVaccin = "necunoscut";
        doze = 0;
    }
    Comanda(string data,string numeClient,string numeVaccin,int doze)
    {
        this->data = data;
        this->numeClient = numeClient;
        this->numeVaccin = numeVaccin;
        this->doze = doze;
        id = 0;
    }

    friend istream& operator>> (istream& in, Comanda& co)
    {
        cout<<"Comanda noua"<<endl;
        cout<<"ID comanda(ex 3): ";
        in>>co.id;
        cout<<"Data comenzii(ex. 23.12.2020): ";
        in>>co.data;
        cout<<"Nume client(ex. SpitalX): ";
        in>>co.numeClient;
        cout<<"Nume vaccin(ex. AntiHepatic): ";
        in>>co.numeVaccin;
        cout<<"Numar doze(ex. 30): ";
        in>>co.doze;

        return in;
    }

    friend ostream& operator<< (ostream& out, Comanda& com)
    {
        out<<endl<<"Comanda cu id-ul "<<com.id<<endl;
        out<<endl<<"Data comenzii: ";
        out<<com.data;
        out<<endl<<"Nume client: ";
        out<<com.numeClient;
        out<<endl<<"Nume vaccin: ";
        out<<com.numeVaccin;
        out<<endl<<"Numar doze: ";
        out<<com.doze;


        return out;
    }

};

class ListaComenzi
{
private:
    vector<Comanda> listaC;
public:

    vector <Comanda>get_lista()
    {
        return listaC;
    }

    ListaComenzi operator+(Comanda& com)
    {
        listaC.push_back(com);
        return *this;
    }

};

int main()
{

    AntiGripal a;

    Hepatita b;

    SarsCov2 c;

    cin>>a>>b>>c;

    cout<<a<<b<<c;

    Vaccin* listav[3];

    listav[0]=new AntiGripal();
    listav[1]=new Hepatita ();
    listav[2]=new SarsCov2();

        for(int i=0; i<3; i++)
            {
                cout<<endl;
                listav[i]->afisareSchemaVaccinare();
            }

    Comanda com1("20-12-2020", "SpitalX", "AntiSarsCov2",20);

    ListaComenzi lista;

    lista=lista+com1;
    cout<<endl;
    cout<<lista.get_lista()[0];
    cout<<endl;

    list<AntiGripal> lista1;
    list<Hepatita> lista2;
    list<SarsCov2> lista3;
    ListaComenzi listaCom;
    string comanda;

    while(comanda != "0")
    {
        cout<<endl<<"1. Adaugare unui vaccin nou"<<endl;
        cout<<"2. Afisarea tuturor vaccinurilor"<<endl;
        cout<<"3. Numele producatorilor pentru toate vaccinurile"<<endl;
        cout<<"4. Adaugarea unei comenzi"<<endl;
        cout<<"5. Afisarea tuturor comenzilor"<<endl;
        cout<<"6. Valoarea comenzilor dintr-o anumita zi"<<endl;
        cout<<"7. Afisarea schemei de vaccinare pentru un anumit tip de vaccin"<<endl;
        cout<<"8. Exportati comenziile intr-un fisier"<<endl;
        cout<<"0. Pentru a opri programul"<<endl;

        cin>>comanda;

        if(comanda == "1")
        {
            cout<<"Tip de vaccin: (1. AntiGripal, 2.AntiHepatic, 3. AntiSars-Cov2)";
            cin>>comanda;
            if(comanda == "1")
            {
                AntiGripal ag;
                cin>>ag;
                lista1.push_back(ag);
            }
            if(comanda == "2")
            {
                Hepatita hep;
                cin>>hep;
                lista2.push_back(hep);
            }
            if(comanda == "3")
            {
                SarsCov2 sa;
                cin>>sa;
                lista3.push_back(sa);
            }
        }
        if(comanda == "2")
        {
            list<AntiGripal> :: iterator i;
            for(i = lista1.begin();i!=lista1.end();++i)
            {
                cout<<*i;
                cout<<endl;
            }
            list<Hepatita> :: iterator j;
            for(j = lista2.begin();j!=lista2.end();++j)
            {
                cout<<*j;
                cout<<endl;
            }
            list<SarsCov2> :: iterator k;
            for(k = lista3.begin();k!=lista3.end();++k)
            {
                cout<<*k;
                cout<<endl;
            }
        }
        if(comanda == "3")
        {
            cout<<"Vaccinuri antigripale produse de: \n";
            list<AntiGripal> :: iterator i;
            for(i = lista1.begin();i!=lista1.end();++i)
            {
                cout<<(*i).get_numeprod();
                cout<<endl;
            }
            cout<<"Vaccinuri antihepatice produse de: \n";
            list<Hepatita> :: iterator j;
            for(j = lista2.begin();j!=lista2.end();++j)
            {
                cout<<(*j).get_numeprod();
                cout<<endl;
            }
            cout<<"Vaccinuri antisars-cov2 produse de: \n";
            list<SarsCov2> :: iterator k;
            for(k = lista3.begin();k!=lista3.end();++k)
            {
                cout<<(*k).get_numeprod();
                cout<<endl;
            }
        }
        if(comanda == "4")
        {
            Comanda co;
            cin>>co;
            listaCom = listaCom+co;

        }
        if(comanda == "5")
        {
            for(int i = 0 ;i < listaCom.get_lista().size();i++ )
                cout<<listaCom.get_lista()[i];
        }
        if(comanda == "6")
        {
            //nu am mai avut timp
        }
        if(comanda == "7")
        {
            //nu am mai avut timp
        }
        if(comanda == "8")
        {
            ofstream fisier;
            fisier.open("Comenzi.txt"); ///trebuie creat un fisier nou cu numele Comenzi.txt
            for(int i = 0 ;i < listaCom.get_lista().size();i++ )
                fisier<<listaCom.get_lista()[i];

        }

    }
    return 0;
}
