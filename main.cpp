#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <map>
#include <set>

//FIERBINTEANU DAVID, GRUPA 142
//MODIFICAT: 08.05.2021

using namespace std;

class Produs
{
protected:
    double pret;
    int kcal;
    string nume;
    int nr_ingrediente;
    string *ingrediente;

    static int nr_produse;
    const int id_produs;

public:
    virtual ostream& AfisareVirtuala(ostream& out)const;
    virtual istream& CitireVirtuala (istream& in);

    friend istream& operator>>(istream & in,Produs& pr);
    friend ostream& operator<<(ostream & out,const Produs& pr);

    double getPret()
    {
        return this->pret;
    }
    int getKcal()
    {
        return this->kcal;
    }
    string getNume()
    {
        return this->nume;
    }
    string *getIngrediente()
    {
        return this->ingrediente;
    }
    int getNr_ingrediente()
    {
        return this->nr_ingrediente;
    }

    void setPret(double pret)
    {
        this->pret=pret;
    }
    void setKcal(int kcal)
    {
        this->kcal=kcal;
    }
    void setNume(string nume)
    {
        this->nume=nume;
    }
    void setNr_ingrediente(int nr_ingrediente)
    {
        this->nr_ingrediente=nr_ingrediente;
    }
    void setIngrediente(string *ingrediente, int nr_ingrediente)
    {
        if(this->ingrediente!=nullptr)
            delete[] this->ingrediente;

        this->ingrediente=new string[nr_ingrediente];
        for(int i=0; i<nr_ingrediente; i++)
            this->ingrediente[i]=ingrediente[i];
    }

    Produs():id_produs(nr_produse++)
    {

    }
};

ostream& Produs::AfisareVirtuala (ostream& out) const
{
    out<<"\nNumele produsului este: "<<nume;
    out<<"\nPretul produsului este: "<<pret;
    return out;
}

istream& Produs::CitireVirtuala(istream& in)
{
    cout<<"\nNumele produsului este: ";
    in>>this->nume;
    cout<<"\nPretul produsului este: ";
    in>>this->pret;
    return in;
}

istream& operator>>(istream & in,Produs& pr)
{
    return pr.CitireVirtuala(in);
}
ostream& operator<<(ostream & out,const Produs& pr)
{
    return pr.AfisareVirtuala(out);
}

class Desert:public Produs
{
private:
    Produs entitate_produs;
public:
    virtual ostream& AfisareVirtuala(ostream& out)const;
    virtual istream& CitireVirtuala (istream& in);

    friend istream& operator>>(istream & in,Desert& d);
    friend ostream& operator<<(ostream & out,const Desert& d);

    Desert():Produs()
    {

    }
    virtual ~Desert()
    {

    }
};

ostream& Desert::AfisareVirtuala (ostream& out) const
{
    out<<"\nNumele produsului este: "<<nume;
    out<<"\nPretul produsului este: "<<pret;
    return out;
}

istream& Desert::CitireVirtuala(istream& in)
{
    cout<<"\nNumele desertului este: ";
    in>>this->nume;
    cout<<"\nPretul desertului este: ";
    in>>this->pret;
    return in;
}

istream& operator>>(istream & in,Desert& d)
{
    return d.CitireVirtuala(in);
}
ostream& operator<<(ostream & out,const Desert& d)
{
    return d.AfisareVirtuala(out);
}

class Bautura:public Produs
{
private:
    Produs entitate_produs;
public:
    virtual ostream& AfisareVirtuala(ostream& out)const;
    virtual istream& CitireVirtuala (istream& in);

    friend istream& operator>>(istream & in,Desert& d);
    friend ostream& operator<<(ostream & out,const Desert& d);

    Bautura():Produs()
    {

    }
    virtual ~Bautura()
    {

    }
};

ostream& Bautura::AfisareVirtuala (ostream& out) const
{
    out<<"\nNumele bauturii este: "<<nume;
    out<<"\nPretul bauturii este: "<<pret;
    return out;
}

istream& Bautura::CitireVirtuala(istream& in)
{
    cout<<"\nNumele bauturii este: ";
    in>>this->nume;
    cout<<"\nPretul bauturii este: ";
    in>>this->pret;
    return in;
}

istream& operator>>(istream & in,Bautura& b)
{
    return b.CitireVirtuala(in);
}
ostream& operator<<(ostream & out,const Bautura& b)
{
    return b.AfisareVirtuala(out);
}

class Pizza:public Produs
{
private:
    Produs entitate_produs;
    char tip_blat;
    bool mozzarella_extra;

    int *comandata_in_ultimele_n_luni;
    int luni;

    int dimensiune;

    const int id_pizza;
    static int nr_pizza;

public:
    string AfisareDimensiune()
    {
        if(dimensiune==1)
            return "Dimensiune mica";
        else if(dimensiune==2)
            return "Dimensiune medie";
        else if(dimensiune==3)
            return "Dimensiune mare";
    }

    //Setters
    void setDimensiune(int dimensiune)
    {
        this->dimensiune=dimensiune;
    }
    void setTip_blat(char tip_blat)
    {
        this->tip_blat=tip_blat;
    }
    void setMozzarella_extra(bool mozzarella_extra)
    {
        this->mozzarella_extra=mozzarella_extra;
    }
    void setComandata_in_ultimele_n_luni(int *com, int n)
    {
        this->luni=n;
        if(this->comandata_in_ultimele_n_luni!=NULL)
            delete[] comandata_in_ultimele_n_luni;
        this->comandata_in_ultimele_n_luni=new int[n];
        for(int i=0; i<n; i++)
            this->comandata_in_ultimele_n_luni[i]=com[i];
    }

    //Getters
    int getDimensiune()
    {
        return this->dimensiune;
    }
    int *getComandata_in_ultimele_n_luni()
    {
        return this->comandata_in_ultimele_n_luni;
    }
    int getLuni()
    {
        return this->luni;
    }
    char getTip_blat()
    {
        return this->tip_blat;
    }
    bool getMozzarella_extra()
    {
        return this->mozzarella_extra;
    }
    const int getId_pizza()
    {
        return id_pizza;
    }
    static int getNr_pizza()
    {
        return nr_pizza;
    }




    //COPY CONSTRUCTOR
    Pizza(const Pizza &copie):id_pizza(copie.id_pizza)
    {
        this->nume=copie.nume;
        this->tip_blat=copie.tip_blat;
        this->pret=copie.pret;
        this->mozzarella_extra=copie.mozzarella_extra;

        this->nr_ingrediente=copie.nr_ingrediente;
        if(this->ingrediente!=NULL)
            delete[] this->ingrediente;
        this->ingrediente=new string[copie.nr_ingrediente];
        for(int i=0; i<copie.nr_ingrediente; i++)
        {
            this->ingrediente[i]=copie.ingrediente[i];
        }

        if(this->comandata_in_ultimele_n_luni!=NULL)
            delete[] this->comandata_in_ultimele_n_luni;
        this->comandata_in_ultimele_n_luni=new int[copie.luni];
        for(int i=0; i<copie.luni; i++)
            this->comandata_in_ultimele_n_luni[i]=copie.comandata_in_ultimele_n_luni[i];
    }

    //OPERATOR DE ASIGNMENT
    Pizza &operator=(const Pizza &pizza2)
    {
        if (this!=&pizza2)
        {
            this->nr_ingrediente=pizza2.nr_ingrediente;
            this->tip_blat=pizza2.tip_blat;
            this->nume=pizza2.nume;
            this->mozzarella_extra=pizza2.mozzarella_extra;

            if(this->ingrediente!=NULL)
                delete[] this->ingrediente;
            this->ingrediente=new string[pizza2.nr_ingrediente];
            for(int i=0; i<pizza2.nr_ingrediente; i++)
                this->ingrediente[i]=pizza2.ingrediente[i];

            if(this->comandata_in_ultimele_n_luni!=NULL)
                delete[] this->comandata_in_ultimele_n_luni;
            this->comandata_in_ultimele_n_luni=new int[pizza2.luni];
            for(int i=0; i<pizza2.luni; i++)
                this->comandata_in_ultimele_n_luni[i]=pizza2.comandata_in_ultimele_n_luni[i];
        }
        return *this;
    }

    //OPERATORUL ==
    bool operator==(const Pizza &copie)
    {
        if(this->nume==copie.nume && this->pret==copie.pret)
            return true;
        return false;
    }

    //OPERATORUL ++ PRE-INCREMENTARE
    Pizza operator++()
    {
        this->pret++;
        return *this;
    }

    //OPERATORUL ++ POST-INCREMENTARE
    const Pizza operator++(int)
    {
        Pizza aux(*this);
        this->pret++;
        return aux;
    }

    //OPERATORUL <
    bool operator<(const Pizza &copie)
    {
        if(this->pret<copie.pret)
            return true;
        return false;
    }

    //OPERATORUL >=
    bool operator>=(const Pizza &copie)
    {
        if(this->pret>=copie.pret)
            return true;
        return false;
    }

    //OPERATORUL +=
    Pizza operator+=(double x)
    {
        this->pret+=x;
        return *this;
    }

    //OPERATORUL +
    Pizza operator+(double x)
    {
        Pizza aux(*this);
        aux.pret=aux.pret+x;
        return aux;
    }

    //OPERATORUL DE INDEXARE
    string operator[](int index);

    //CONSTRUCTOR FARA PARAMETRI
    Pizza():id_pizza(nr_pizza++)
    {
        nume="neinitializat";
        tip_blat='x';
        pret=0;
        mozzarella_extra=false;
        nr_ingrediente=0;
        ingrediente=nullptr;
        luni=0;
        comandata_in_ultimele_n_luni=nullptr;
    }

    //CONSTRUCTOR CU 2 PARAMETRI
    Pizza(string nume, bool mozzarella_extra):id_pizza(nr_pizza++)
    {
        this->nume=nume;
        this->mozzarella_extra=mozzarella_extra;
        this->pret=0;
    }

    //CONSTRUCTOR CU 3 PARAMETRI
    Pizza(string nume, bool mozzarella_extra, char tip_blat):id_pizza(nr_pizza++)
    {
        this->nume=nume;
        this->mozzarella_extra=mozzarella_extra;
        this->tip_blat=tip_blat;
        this->pret=0;
    }

    string AreMozzarella()
    {
        if(this->mozzarella_extra==true)
            return "Mozzarella extra";
        else
            return "Fara Mozzarella extra";
    }

    string TipulDeBlat()
    {
        if(this->tip_blat=='c')
            return "Blat clasic";
        else if(this->tip_blat=='i')
            return "Blat italian";
        else if(this->tip_blat=='p')
            return "Blat pufos";
    }

    //DESTRUCTOR
    ~Pizza()
    {
        if(this->ingrediente!=NULL)
        {
            delete[] this->ingrediente;
        }
        if(this->comandata_in_ultimele_n_luni!=NULL)
        {
            delete[] this->comandata_in_ultimele_n_luni;
        }
    }

    //CAST OPERATOR
    explicit operator int()
    {
        return (int)this->pret;
    }

};

class Adresa
{
private:
    string localitate;
    char *strada=nullptr;
    int numar_strada;
    string bloc;
    char scara;
    int apartament;

    const int id_adresa;
    static int nr_adrese;
public:
    //Getters
    string getLocalitate()
    {
        return this->localitate;
    }
    char *getStrada()
    {
        return this->strada;
    }
    int getNumar_strada()
    {
        return this->numar_strada;
    }
    string getBloc()
    {
        return this->bloc;
    }
    char getScara()
    {
        return this->scara;
    }
    int getApartament()
    {
        return this->apartament;
    }
    static int getNr_adrese()
    {
        return nr_adrese;
    }

    //Setters
    void setLocalitate(string localitate)
    {
        this->localitate=localitate;
    }
    void setStrada(char* strada2)
    {
        if(strada!=nullptr)
        {
            delete[] strada;
        }
        strada=new char[strlen(strada2)+1];
        strcpy(strada,strada2);
    }
    void setNumar_strada(int numar_strada)
    {
        this->numar_strada=numar_strada;
    }
    void setBloc(string bloc)
    {
        this->bloc=bloc;
    }
    void setScara(char scara)
    {
        this->scara=scara;
    }
    void setApartament(int apartament)
    {
        this->apartament=apartament;
    }

    //COPY CONSTRUCTOR
    Adresa(const Adresa &copie):id_adresa(copie.id_adresa)
    {
        this->localitate=copie.localitate;

        if(this->strada != nullptr)
        {
            delete[] this->strada;
        }
        this->strada = new char[strlen(copie.strada)+1];
        strcpy(this->strada,copie.strada);

        this->numar_strada=copie.numar_strada;
        this->bloc=copie.bloc;
        this->scara=copie.scara;
        this->apartament=copie.apartament;
    }

    //CONSTRUCTOR CU UN PARAMETRU
    Adresa(string localitate):id_adresa(nr_adrese++)
    {
        this->localitate=localitate;
    }

    //CONSTRUCTOR FARA PARAMETRI
    Adresa():id_adresa(nr_adrese++)
    {
        localitate="neinitializat";
        this->strada=nullptr;
        numar_strada=0;
        bloc="neinitializat";
        scara='1';
        apartament=0;
    }

    //DESTRUCTOR
    ~Adresa()
    {
        if(this->strada != nullptr)
        {
            delete[] this->strada;
        }
    }
};

class Cont
{
private:
    string email;
    string nume;
    string prenume;
    string parola;

    int *comenzi_in_ultimele_n_luni=nullptr;
    int luni;

    const int id_cont;
    static int nr_conturi;
public:
    //Getters
    int* getComenzi_in_ultimele_n_luni()
    {
        return comenzi_in_ultimele_n_luni;
    }

    string getEmail()
    {
        return this->email;
    }
    string getNume()
    {
        return this->nume;
    }
    string getPrenume()
    {
        return this->prenume;
    }
    string getParola()
    {
        return this->parola;
    }
    static int getNr_conturi()
    {
        return nr_conturi;
    }

    //Setters
    int *setComenzi_in_ultimele_n_luni(int*comenzi, int luni)
    {
        this->luni=luni;
        if(this->comenzi_in_ultimele_n_luni!=nullptr)
            delete[] this->comenzi_in_ultimele_n_luni;

        this->comenzi_in_ultimele_n_luni=new int[luni];

        for(int i=0; i<luni; i++)
            this->comenzi_in_ultimele_n_luni[i]=comenzi[i];
    }

    void setEmail(string email)
    {
        this->email=email;
    }
    void setNume(string nume)
    {
        this->nume=nume;
    }
    void setPrenume(string prenume)
    {
        this->prenume=prenume;
    }
    void setParola(string parola)
    {
        this->parola=parola;
    }

    //OPERATOR CITIRE
    friend istream& operator>>(istream& in, Cont& c);

    //OPERATOR AFISARE
    friend ostream& operator<<(ostream& out, const Cont& c);

    //COPY CONSTRUCTOR
    Cont(const Cont &copie):id_cont(copie.id_cont)
    {
        this->email=copie.email;
        this->nume=copie.nume;
        this->prenume=copie.prenume;
        this->parola=copie.parola;

        if(this->comenzi_in_ultimele_n_luni!=nullptr)
            delete[] this->comenzi_in_ultimele_n_luni;
        this->comenzi_in_ultimele_n_luni=new int[copie.luni];
        this->comenzi_in_ultimele_n_luni=copie.comenzi_in_ultimele_n_luni;
    }

    //CONSTRUCTOR CU 2 PARAMETRI
    Cont(string email, string parola):id_cont(nr_conturi++)
    {
        this->email=email;
        this->parola=parola;
    }

    //CONSTRUCTOR FARA PARAMETRI
    Cont():id_cont(nr_conturi++)
    {
        email="neinitializat";
        nume="neinitializat";
        prenume="neinitializat";
        parola="neinitializat";
        comenzi_in_ultimele_n_luni=nullptr;
        luni=0;
    }

    //DESTRUCTOR
    ~Cont()
    {
        if(this->comenzi_in_ultimele_n_luni!=nullptr)
            delete[] this->comenzi_in_ultimele_n_luni;
    }
};

//OPERATORUL >> PENTRU CLASA CONT
istream& operator>>(istream& in, Cont& c)
{
    char aux[64];
    cout<<"Prenume: ";
    in>>aux;
    c.prenume=aux;

    cout<<"Nume: ";
    //in>>p.prenume;
    in>>aux;
    c.nume=aux;

    cout<<"E-mail: ";
    //in>>p.varsta;
    in>>aux;
    c.email=aux;

    cout<<"Parola: ";
    //in>>p.angajat;
    in>>aux;
    c.parola=aux;

    return in;
}

//OPERATORUL << PENTRU CLASA CONT
ostream& operator<<(ostream& out, const Cont& c)
{
    out<<"Prenume: "<<c.prenume;
    out<<"\nNume: "<<c.nume;
    out<<"\nE-mail: "<<c.email;

    return out;
}

void setcolor (unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

ifstream fin ("fisier.in");
ofstream fout ("fisier.out");

int Pizza::nr_pizza=0;
int Adresa::nr_adrese=0;
int Cont::nr_conturi=0;
int Produs::nr_produse=0;

int i_for_adresa;

char key_meniu, key_pizza_choice, key_useless, key_extra_mozzarella, key_order, key_dimensiune, key_tip_blat, key_menu_type, key_dessert_choice, key_drink_choice, key_ingredients;

int i_adresa=1, i_cont=1, i_email_existent, i_pizza_comandata, numar_adrese, numar_conturi, i_dessert_choice, i_drink_choice, i_for_bauturi, i_for_deserturi;

int clr_ingredient_1=7, clr_ingredient_2=7, clr_ingredient_3=7, clr_ingredient_4=7, clr_ingredient_5=7, clr_ingredient_6=7, clr_ingredient_7=7, clr_ingredient_8=7;
int counter_ingredient_1, counter_ingredient_2, counter_ingredient_3, counter_ingredient_4, counter_ingredient_5, counter_ingredient_6, counter_ingredient_7, counter_ingredient_8;

int basket[30], basket_items;
double basket_total, menu_pizza_price[7];

bool autentificat=true;

double pret_pizza_custom;

vector<Pizza> p;
set<string> bset;
list<Adresa> a;
map<string, double> dmap;

Desert d[16];
Bautura b[16];
Cont c[16];

Pizza pizza_aux;
Adresa adresa_aux;
Bautura bautura_aux;

void meniu()
{
    system("cls");
    if(autentificat==false)
    {
        cout<<"\n    Bun venit la ";
        setcolor(4);
        cout<<"Pizzeria orientata pe blat!\n";
        setcolor(7);
        cout<<"\n\n     ";
        setcolor(4);
        cout<<"1.";
        setcolor(7);
        cout<<" Vezi meniul nostru";
        cout<<"\n     ";
        setcolor(4);
        cout<<"2.";
        setcolor(7);
        cout<<" Creeaza propria pizza";
        cout<<"\n\n     ";
        setcolor(4);
        cout<<"3.";
        setcolor(7);
        cout<<" Autentificare (log-in)";
        cout<<"\n     ";
        setcolor(4);
        cout<<"4.";
        setcolor(7);
        cout<<" Inregistrare (register)";
        cout<<"\n\n     ";
        setcolor(4);
        cout<<"5.";
        setcolor(7);
        cout<<" Adauga o adresa noua";
        cout<<"\n     ";
        setcolor(4);
        cout<<"6.";
        setcolor(7);
        cout<<" Vizualizati adresele salvate";
        cout<<"\n\n     ";
        setcolor(4);
        cout<<"7.";
        setcolor(7);
        cout<<" Vreau sa ies din Pizzeria orientata pe blat";
    }
    else
    {
        cout<<"\n    Bun venit la ";
        setcolor(4);
        cout<<"Pizzeria orientata pe blat";
        setcolor(7);
        cout<<", "<<c[i_email_existent].getPrenume()<<"!\n";
        cout<<"\n\n     ";
        setcolor(4);
        cout<<"1.";
        setcolor(7);
        cout<<" Vezi meniul nostru";
        cout<<"\n     ";
        setcolor(4);
        cout<<"2.";
        setcolor(7);
        cout<<" Creeaza propria pizza";
        cout<<"\n\n     ";
        setcolor(4);
        cout<<"3.";
        setcolor(7);
        cout<<" Autentificare (log-in)";
        cout<<"\n     ";
        setcolor(4);
        cout<<"4.";
        setcolor(7);
        cout<<" Inregistrare (register)";
        cout<<"\n\n     ";
        setcolor(4);
        cout<<"5.";
        setcolor(7);
        cout<<" Adauga o adresa noua";
        cout<<"\n     ";
        setcolor(4);
        cout<<"6.";
        setcolor(7);
        cout<<" Vizualizati adresele salvate";
        cout<<"\n\n     ";
        setcolor(4);
        cout<<"7.";
        setcolor(7);
        cout<<" Vreau sa ies din Pizzeria orientata pe blat";
        cout<<"\n\n     ";
        setcolor(4);
        cout<<"8.";
        setcolor(7);
        cout<<" Delogare (log-out)";
    }
}

string Pizza::operator[](int index)
{
    if(index>=Pizza::getNr_pizza() )
    {
        return "Nu exista";
    }
    return "Exista";
}

int main()
{
    srand (time(NULL));

    string ing1[]= {"Sos tomat","Branza Mozzarella","Sunca","Ciuperci","Masline"};
    string ing2[]= {"Sos tomat","Branza Mozzarella","Bacon","Sunca","Ciuperci","Ardei","Masline"};
    string ing3[]= {"Sos tomat","Branza Mozzarella","Salam Pepperoni"};
    string ing4[]= {"Sos tomat","Branza Mozzarella","Pui","Porumb","Ardei"};
    string ing5[]= {"Sos tomat","Branza Mozzarella","Sunca","Ciuperci","Vita"};
    string ing6[]= {"Sos tomat","Branza Mozzarella","Dovlecel","Ardei","Ciuperci"};

    pizza_aux.setNume("Roma");
    pizza_aux.setNr_ingrediente(5);
    pizza_aux.setIngrediente(ing1,5);
    //string *ing_1=pizza_aux.getIngrediente();
    p.push_back(pizza_aux);

    pizza_aux.setNume("Nevada");
    pizza_aux.setNr_ingrediente(7);
    pizza_aux.setIngrediente(ing2,7);
    //string *ing_2=pizza_aux.getIngrediente();
    p.push_back(pizza_aux);

    pizza_aux.setNume("Pepperoni");
    pizza_aux.setNr_ingrediente(3);
    pizza_aux.setIngrediente(ing3,3);
    //string *ing_3=pizza_aux.getIngrediente();
    p.push_back(pizza_aux);

    pizza_aux.setNume("California");
    pizza_aux.setNr_ingrediente(5);
    pizza_aux.setIngrediente(ing4,5);
    //string *ing_4=pizza_aux.getIngrediente();
    p.push_back(pizza_aux);

    pizza_aux.setNume("Europeana");
    pizza_aux.setNr_ingrediente(5);
    pizza_aux.setIngrediente(ing5,5);
    //string *ing_5=pizza_aux.getIngrediente();
    p.push_back(pizza_aux);

    pizza_aux.setNume("Vegetariana");
    pizza_aux.setNr_ingrediente(5);
    pizza_aux.setIngrediente(ing6,5);
    //string *ing_6=pizza_aux.getIngrediente();
    p.push_back(pizza_aux);


    d[1].setNume("Tort Oreo");
    d[2].setNume("Inghetata cu ciocolata");
    d[3].setNume("Inghetata cu vanilie");
    d[4].setNume("Profiterol");

    d[1].setPret(14.49);
    d[2].setPret(8.39);
    d[3].setPret(8.39);
    d[4].setPret(12.79);

    b[1].setNume("Apa Plata 330ml");
    b[1].setPret(3.79);
    bset.insert("Coca-Cola 330ml");

    b[2].setNume("Coca-Cola 330ml");
    b[2].setPret(4.49);
    bset.insert("Fanta 330ml");

    b[3].setNume("Fanta 330ml");
    b[3].setPret(4.49);
    bset.insert("Sprite 330ml");

    b[4].setNume("Limonada 500ml");
    b[4].setPret(8.99);
    bset.insert("Apa Plata 330ml");

    b[5].setNume("Sprite 330ml");
    b[5].setPret(4.49);
    bset.insert("Limonada 500ml");

    dmap["Tort Oreo"] = 14.49;
    dmap["Inghetata cu ciocolata"] = 8.39;
    dmap["Inghetata cu vanilie"] = 8.39;
    dmap["Profiterol"] = 12.79;

    meniu();
    while(true)
    {
        clr_ingredient_1=7, clr_ingredient_2=7, clr_ingredient_3=7, clr_ingredient_4=7, clr_ingredient_5=7, clr_ingredient_6=7, clr_ingredient_7=7, clr_ingredient_8=7;
        counter_ingredient_1=0, counter_ingredient_2=0, counter_ingredient_3=0, counter_ingredient_4=0, counter_ingredient_5=0, counter_ingredient_6=0, counter_ingredient_7=0, counter_ingredient_8=0;
        key_meniu=getch();
        if(autentificat==true)
        {
            if(key_meniu=='8')
            {
                do
                {
                    system("cls");
                    cout<<"Esti sigur ca vrei sa iesi din cont? (1/da, 2/nu)";
                    key_useless=getch();
                }
                while(key_useless!='1' && key_useless!='2');

                if(key_useless=='1')
                {
                    autentificat=false;
                    meniu();
                }
                else
                {
                    meniu();
                }

            }
        }
        if (key_meniu != '1' && key_meniu != '2' && key_meniu != '3' && key_meniu != '4' && key_meniu!='5' && key_meniu!='6' && key_meniu!='7')
        {
            meniu();
        }
        else
        {
            if (key_meniu == '7')
            {
                break;
            }
            else if (key_meniu == '1')  //COMANDA DIN MENIU
            {
                if(autentificat==true && numar_adrese>0)
                {
                    basket_total=0; //valoare cos
                    for(int i=1; i<=15; i++)
                        basket[i]=0;
                    basket_items=0; //nr produse cos
                    for(int i=1; i<=6; i++) //pretul pt fiecare pizza
                        menu_pizza_price[i]=0;
                    do
                    {
                        do
                        {
                            system("cls");
                            cout<<"Ce doriti sa comandati?\n\n  ";
                            setcolor(4);
                            cout<<"1";
                            setcolor(7);
                            cout<<". Pizza\n  ";
                            setcolor(4);
                            cout<<"2";
                            setcolor(7);
                            cout<<". Desert\n  ";
                            setcolor(4);
                            cout<<"3";
                            setcolor(7);
                            cout<<". Bauturi racoritoare\n\n ";
                            setcolor(10);
                            cout<<"5";
                            setcolor(7);
                            cout<<". Vizualizare cos";
                            key_menu_type=getch();
                        }
                        while(key_menu_type!='1' && key_menu_type!='2' && key_menu_type!='3' && key_menu_type!='5');

                        if(key_menu_type=='1') // MENIU PIZZA
                        {
                            do
                            {
                                system("cls");
                                cout<<"Alegeti o pizza:\n";
                                cout<<"\n  1. ";
                                setcolor (4);
                                cout<<p[0].getNume();
                                setcolor(7);
                                cout<<"  (";
                                for(int i=0; i<p[0].getNr_ingrediente(); i++)
                                {
                                    if(i==p[0].getNr_ingrediente()-1)
                                        cout<<ing1[i];
                                    else
                                        cout<<ing1[i]<<", ";
                                }
                                cout<<")\n  2. ";
                                setcolor (4);
                                cout<<p[1].getNume();
                                setcolor(7);
                                cout<<"  (";
                                for(int i=0; i<p[1].getNr_ingrediente(); i++)
                                {
                                    if(i==p[1].getNr_ingrediente()-1)
                                        cout<<ing2[i];
                                    else
                                        cout<<ing2[i]<<", ";
                                }
                                cout<<")\n  3. ";
                                setcolor (4);
                                cout<<p[2].getNume();
                                setcolor(7);
                                cout<<"  (";
                                for(int i=0; i<p[2].getNr_ingrediente(); i++)
                                {
                                    if(i==p[2].getNr_ingrediente()-1)
                                        cout<<ing3[i];
                                    else
                                        cout<<ing3[i]<<", ";
                                }
                                cout<<")\n  4. ";
                                setcolor (4);
                                cout<<p[3].getNume();
                                setcolor(7);
                                cout<<"  (";
                                for(int i=0; i<p[3].getNr_ingrediente(); i++)
                                {
                                    if(i==p[3].getNr_ingrediente()-1)
                                        cout<<ing4[i];
                                    else
                                        cout<<ing4[i]<<", ";
                                }
                                cout<<")\n  5. ";
                                setcolor (4);
                                cout<<p[4].getNume();
                                setcolor(7);
                                cout<<"  (";
                                for(int i=0; i<p[4].getNr_ingrediente(); i++)
                                {
                                    if(i==p[4].getNr_ingrediente()-1)
                                        cout<<ing5[i];
                                    else
                                        cout<<ing5[i]<<", ";
                                }
                                cout<<")\n  6. ";
                                setcolor (4);
                                cout<<p[5].getNume();
                                setcolor(7);
                                cout<<"  (";
                                for(int i=0; i<p[5].getNr_ingrediente(); i++)
                                {
                                    if(i==p[5].getNr_ingrediente()-1)
                                        cout<<ing6[i];
                                    else
                                        cout<<ing6[i]<<", ";
                                }
                                cout<<")";
                                key_pizza_choice=getch();
                            }
                            while(key_pizza_choice!='1' && key_pizza_choice!='2' && key_pizza_choice!='3' && key_pizza_choice!='4' && key_pizza_choice!='5' && key_pizza_choice!='6');

                            if(key_pizza_choice=='1')
                            {
                                i_pizza_comandata=1;
                                basket[1]++;
                                basket_items++;
                            }
                            else if(key_pizza_choice=='2')
                            {
                                i_pizza_comandata=2;
                                basket[2]++;
                                basket_items++;
                            }
                            else if(key_pizza_choice=='3')
                            {
                                i_pizza_comandata=3;
                                basket[3]++;
                                basket_items++;
                            }
                            else if(key_pizza_choice=='4')
                            {
                                i_pizza_comandata=4;
                                basket[4]++;
                                basket_items++;
                            }
                            else if(key_pizza_choice=='5')
                            {
                                i_pizza_comandata=5;
                                basket[5]++;
                                basket_items++;
                            }
                            else if(key_pizza_choice=='6')
                            {
                                i_pizza_comandata=6;
                                basket[6]++;
                                basket_items++;
                            }

                            do
                            {
                                system("cls");
                                cout<<"Doriti mozzarella extra pentru 2.50 lei? (1-Da/ 2-Nu)";
                                key_extra_mozzarella=getch();
                            }
                            while(key_extra_mozzarella!='1' && key_extra_mozzarella!='2');
                            if(key_extra_mozzarella=='1')
                            {
                                p[i_pizza_comandata].setMozzarella_extra(true);
                                basket_total+=2.5;
                                menu_pizza_price[i_pizza_comandata]+=2.5;
                            }
                            do
                            {
                                cout<<"\n\nAlegeti dimensiunea: (1-Mica, 17 lei/ 2-Medie, 24 lei/ 3-Mare, 31 lei)";
                                key_dimensiune=getch();

                            }
                            while(key_dimensiune!='1' && key_dimensiune!='2' && key_dimensiune!='3');
                            if(key_dimensiune=='1')
                            {
                                basket_total+=17;
                                menu_pizza_price[i_pizza_comandata]+=17;
                                p[i_pizza_comandata].setDimensiune(1);
                            }
                            else if(key_dimensiune=='2')
                            {
                                basket_total+=24;
                                menu_pizza_price[i_pizza_comandata]+=24;
                                p[i_pizza_comandata].setDimensiune(2);
                            }
                            else if(key_dimensiune=='3')
                            {
                                basket_total+=31;
                                menu_pizza_price[i_pizza_comandata]+=31;
                                p[i_pizza_comandata].setDimensiune(3);
                            }

                            do
                            {
                                cout<<"\n\nAlegeti tipul de blat: (1-Clasic/ 2-Pufos/ 3-Italian)";
                                key_tip_blat=getch();
                            }
                            while(key_tip_blat!='1' && key_tip_blat!='2' && key_tip_blat!='3');

                            if(key_tip_blat=='1')
                            {
                                p[i_pizza_comandata].setTip_blat('c');
                            }
                            else if(key_tip_blat=='2')
                            {
                                p[i_pizza_comandata].setTip_blat('p');
                            }
                            else if(key_tip_blat=='3')
                            {
                                p[i_pizza_comandata].setTip_blat('i');
                            }
                            p[i_pizza_comandata].setPret(menu_pizza_price[i_pizza_comandata]);
                            system("cls");
                            cout<<"Produs adaugat in cos.\n\nApasati orice tasta pentru a continua.";
                            key_useless=getch();


                        }
                        else if(key_menu_type=='2')//MENIU DESERT
                        {
                            i_for_deserturi=0;
                            do
                            {
                                system("cls");
                                cout<<"Deserturi:\n";

                                for(map<string, double>::iterator iter=dmap.begin(); iter!=dmap.end(); iter++)
                                {
                                    cout<<"\n  "<<++i_for_deserturi<<". "<<iter->first<<" - "<<iter->second<<" lei";
                                }

                                key_dessert_choice=getch();
                            }
                            while(key_dessert_choice!='1' && key_dessert_choice!='2' && key_dessert_choice!='3' && key_dessert_choice!='4');

                            if(key_dessert_choice=='1')
                            {
                                i_dessert_choice=1;
                                basket[7]++;
                                basket_total+=8.39;
                                basket_items++;
                            }
                            else if(key_dessert_choice=='2')
                            {
                                i_dessert_choice=2;
                                basket[8]++;
                                basket_total+=8.39;
                                basket_items++;
                            }
                            else if(key_dessert_choice=='3')
                            {
                                i_dessert_choice=3;
                                basket[9]++;
                                basket_total+=12.79;
                                basket_items++;
                            }
                            else if(key_dessert_choice=='4')
                            {
                                i_dessert_choice=4;
                                basket[10]++;
                                basket_total+=14.49;
                                basket_items++;
                            }
                            system("cls");
                            cout<<"Produs adaugat in cos.\n\nApasati orice tasta pentru a continua.";
                            key_useless=getch();
                        }
                        else if(key_menu_type=='3')//MENIU BAUTURI
                        {
                            do
                            {
                                system("cls");
                                i_for_bauturi=0;
                                cout<<"Bauturi:\n";
                                for(set<string>::iterator iter=bset.begin(); iter!=bset.end(); iter++)
                                {
                                    cout<<"\n  "<<++i_for_bauturi<<". "<<*iter<<" - "<<b[i_for_bauturi].getPret()<<" lei";
                                }
                                key_drink_choice=getch();
                            }
                            while(key_drink_choice!='1' && key_drink_choice!='2' && key_drink_choice!='3' && key_drink_choice!='4' && key_drink_choice!='5');

                            if(key_drink_choice=='1')
                            {
                                i_drink_choice=1;
                                basket[11]++;
                                basket_total+=3.79;
                                basket_items++;
                            }
                            else if(key_drink_choice=='2')
                            {
                                i_drink_choice=2;
                                basket[12]++;
                                basket_total+=4.49;
                                basket_items++;
                            }
                            else if(key_drink_choice=='3')
                            {
                                i_drink_choice=3;
                                basket[13]++;
                                basket_total+=4.49;
                                basket_items++;
                            }
                            else if(key_drink_choice=='4')
                            {
                                i_drink_choice=4;
                                basket[14]++;
                                basket_total+=8.99;
                                basket_items++;
                            }
                            else if (key_drink_choice=='5')
                            {
                                i_drink_choice=5;
                                basket[15]++;
                                basket_total+=4.49;
                                basket_items++;
                            }

                            system("cls");
                            cout<<"Produs adaugat in cos.\n\nApasati orice tasta pentru a continua.";
                            key_useless=getch();

                        }
                        else if(key_menu_type=='5') // VIZUALIZARE COS
                        {
                            if(basket_items==0)
                            {
                                system("cls");
                                cout<<"Nu aveti niciun produs in cos!\n\nApasati orice tasta pentru a continua.";
                                key_useless=getch();
                                meniu();
                            }
                            else
                            {
                                system("cls");
                                cout<<"Sumar comanda:\n\n";
                                for(int i=1; i<=15; i++)
                                {
                                    if(basket[i]!=0)
                                    {
                                        setcolor(9);
                                        cout<<"  "<<basket[i];
                                        setcolor(7);
                                        cout<<"x ";
                                        if(i==1)
                                        {
                                            cout<<"Pizza Roma - ";
                                            setcolor(9);
                                            cout<<menu_pizza_price[i];
                                            setcolor(7);
                                            cout<<" Lei\n";
                                            cout<<"    " << p[i].AfisareDimensiune() << "\n    "<<p[i].AreMozzarella()<<"\n    "<<p[i].TipulDeBlat()<<"\n\n";
                                        }
                                        else if(i==2)
                                        {
                                            cout<<"Pizza Nevada - ";
                                            setcolor(9);
                                            cout<<menu_pizza_price[i];
                                            setcolor(7);
                                            cout<<" Lei\n";
                                            cout<<"    "<<p[i].AfisareDimensiune()<<"\n    "<<p[i].AreMozzarella()<<"\n    "<<p[i].TipulDeBlat()<<"\n\n";
                                        }
                                        else if(i==3)
                                        {
                                            cout<<"Pizza Pepperoni - ";
                                            setcolor(9);
                                            cout<<menu_pizza_price[i];
                                            setcolor(7);
                                            cout<<" Lei\n";
                                            cout<<"    "<<p[i].AfisareDimensiune()<<"\n    "<<p[i].AreMozzarella()<<"\n    "<<p[i].TipulDeBlat()<<"\n\n";
                                        }
                                        else if(i==4)
                                        {
                                            cout<<"Pizza California - ";
                                            setcolor(9);
                                            cout<<menu_pizza_price[i];
                                            setcolor(7);
                                            cout<<" Lei\n";
                                            cout<<"    "<<p[i].AfisareDimensiune()<<"\n    "<<p[i].AreMozzarella()<<"\n    "<<p[i].TipulDeBlat()<<"\n\n";
                                        }
                                        else if(i==5)
                                        {
                                            cout<<"Pizza Europeana - ";
                                            setcolor(9);
                                            cout<<menu_pizza_price[i];
                                            setcolor(7);
                                            cout<<" Lei\n";
                                            cout<<"    "<<p[i].AfisareDimensiune()<<"\n    "<<p[i].AreMozzarella()<<"\n    "<<p[i].TipulDeBlat()<<"\n\n";
                                        }
                                        else if(i==6)
                                        {
                                            cout<<"Pizza Vegetariana - ";
                                            setcolor(9);
                                            cout<<menu_pizza_price[i];
                                            setcolor(7);
                                            cout<<" Lei\n";
                                            cout<<"    "<<p[i].AfisareDimensiune()<<"\n    "<<p[i].AreMozzarella()<<"\n    "<<p[i].TipulDeBlat()<<"\n\n";
                                        }

                                        else if(i==7)
                                        {
                                            cout<<"Inghetata cu ciocolata - ";
                                            setcolor(9);
                                            cout<<8.39*basket[i];
                                            setcolor(7);
                                            cout<<" Lei\n\n";
                                        }
                                        else if(i==8)
                                        {
                                            cout<<"Inghetata cu vanilie - ";
                                            setcolor(9);
                                            cout<<8.39*basket[i];
                                            setcolor(7);
                                            cout<<" Lei\n\n";
                                        }
                                        else if(i==9)
                                        {
                                            cout<<"Profiterol - ";
                                            setcolor(9);
                                            cout<<12.79*basket[i];
                                            setcolor(7);
                                            cout<<" Lei\n\n";
                                        }
                                        else if(i==10)
                                        {
                                            cout<<"Tort Oreo - ";
                                            setcolor(9);
                                            cout<<14.49*basket[i];
                                            setcolor(7);
                                            cout<<" Lei\n\n";
                                        }

                                        else if(i==11)
                                        {
                                            cout<<"Apa Plata 330ml - ";
                                            setcolor(9);
                                            cout<<3.79*basket[i];
                                            setcolor(7);
                                            cout<<" Lei\n\n";
                                        }
                                        else if(i==12)
                                        {
                                            cout<<"Coca-Cola 330ml - ";
                                            setcolor(9);
                                            cout<<4.49*basket[i];
                                            setcolor(7);
                                            cout<<" Lei\n\n";
                                        }
                                        else if(i==13)
                                        {
                                            cout<<"Fanta 330ml - ";
                                            setcolor(9);
                                            cout<<4.49*basket[i];
                                            setcolor(7);
                                            cout<<" Lei\n\n";
                                        }
                                        else if(i==14)
                                        {
                                            cout<<"Limonada 500ml - ";
                                            setcolor(9);
                                            cout<<8.99*basket[i];
                                            setcolor(7);
                                            cout<<" Lei\n\n";
                                        }
                                        else if(i==15)
                                        {
                                            cout<<"Sprite 330ml - ";
                                            setcolor(9);
                                            cout<<4.49*basket[i];
                                            setcolor(7);
                                            cout<<" Lei\n\n";
                                        }

                                    }
                                }
                                cout<<"Total comanda: ";
                                setcolor(9);
                                cout<<basket_total;
                                setcolor(7);
                                cout<<" Lei\n\nApasati orice tasta pentru a plasa comanda.";
                                key_useless=getch();

                                system("cls");
                                i_for_adresa=0;
                                for(list<Adresa>::iterator iter=a.begin(); iter!=a.end(); iter++)
                                {
                                    cout<<++i_for_adresa<<". Localitatea "<<(*iter).getLocalitate()<<", strada "<<(*iter).getStrada()<<", numar "<<(*iter).getNumar_strada()<<", bloc "<<(*iter).getBloc()<<", scara "<<(*iter).getScara()<<", apartament "<<(*iter).getApartament()<<"\n";
                                }
                                cout<<"\nAlegeti adresa livrarii.";
                                key_useless=getch();

                                system("cls");
                                cout<<"Comanda inregistrata cu succes! Timp aproximativ de livrare: ";
                                setcolor(9);
                                cout<<rand() % 60 + 31;
                                setcolor(7);
                                cout<<" de minute";
                                cout<<"\n\nApasati orice tasta pentru a continua.";
                                key_useless=getch();
                                meniu();
                            }

                        }
                    }
                    while(key_menu_type!='5');
                }

                else
                {
                    system("cls");
                    cout<<"Trebuie sa va autentificati si sa adaugati cel putin o adresa pentru a plasa o comanda.\n\nApasati orice tasta pentru a continua.";
                    key_useless=getch();
                    meniu();
                }
            }
            else if (key_meniu == '2')  //CREEAZA PROPRIA PIZZA
            {
                if(autentificat==true && numar_adrese>0)
                {
                    pret_pizza_custom=0;
                    p[7].setNume("personalizata");

                    do
                    {
                        system("cls");
                        cout<<"Alegeti ingredientele:\n\n";
                        setcolor(clr_ingredient_1);
                        cout<<"  1. Pui (+2.50 Lei)\n";
                        setcolor(clr_ingredient_2);
                        cout<<"  2. Ton (+2.50 Lei)\n";
                        setcolor(clr_ingredient_3);
                        cout<<"  3. Sunca (+2.50 Lei)\n";
                        setcolor(clr_ingredient_4);
                        cout<<"  4. Ciuperci (+2 Lei)\n";
                        setcolor(clr_ingredient_5);
                        cout<<"  5. Masline (+2 Lei)\n";
                        setcolor(clr_ingredient_6);
                        cout<<"  6. Porumb (+2 Lei)\n";
                        setcolor(clr_ingredient_7);
                        cout<<"  7. Rosii (+2 Lei)\n";
                        setcolor(clr_ingredient_8);
                        cout<<"  8. Branza Feta (+2 Lei)\n\n";
                        setcolor(10);
                        cout<<" 9. Continua spre comanda";
                        setcolor(7);
                        key_ingredients=getch();

                        if(key_ingredients=='1' && counter_ingredient_1==0)
                        {
                            clr_ingredient_1=8;
                            pret_pizza_custom+=2.5;
                            counter_ingredient_1++;
                        }
                        else if(key_ingredients=='2' && counter_ingredient_2==0)
                        {
                            clr_ingredient_2=8;
                            pret_pizza_custom+=2.5;
                            counter_ingredient_2++;
                        }
                        else if(key_ingredients=='3' && counter_ingredient_3==0)
                        {
                            clr_ingredient_3=8;
                            pret_pizza_custom+=2.5;
                            counter_ingredient_3++;
                        }
                        else if(key_ingredients=='4' && counter_ingredient_4==0)
                        {
                            clr_ingredient_4=8;
                            pret_pizza_custom+=2;
                            counter_ingredient_4++;
                        }
                        else if(key_ingredients=='5' && counter_ingredient_5==0)
                        {
                            clr_ingredient_5=8;
                            pret_pizza_custom+=2;
                            counter_ingredient_5++;
                        }
                        else if(key_ingredients=='6' && counter_ingredient_6==0)
                        {
                            clr_ingredient_6=8;
                            pret_pizza_custom+=2;
                            counter_ingredient_6++;
                        }
                        else if(key_ingredients=='7' && counter_ingredient_7==0)
                        {
                            clr_ingredient_7=8;
                            pret_pizza_custom+=2;
                            counter_ingredient_7++;
                        }
                        else if(key_ingredients=='8' && counter_ingredient_8==0)
                        {
                            clr_ingredient_8=8;
                            pret_pizza_custom+=2;
                            counter_ingredient_8++;
                        }

                    }
                    while(key_ingredients!='9');


                    do
                    {
                        system("cls");
                        cout<<"Doriti mozzarella extra pentru 2.50 lei? (1-Da/ 2-Nu)";
                        key_extra_mozzarella=getch();
                    }
                    while(key_extra_mozzarella!='1' && key_extra_mozzarella!='2');

                    if(key_extra_mozzarella=='1')
                    {
                        p[7].setMozzarella_extra(true);
                        pret_pizza_custom+=2.5;
                    }
                    do
                    {
                        cout<<"\n\nAlegeti dimensiunea: (1-Mica, 17 lei/ 2-Medie, 24 lei/ 3-Mare, 31 lei)";
                        key_dimensiune=getch();

                    }
                    while(key_dimensiune!='1' && key_dimensiune!='2' && key_dimensiune!='3');
                    if(key_dimensiune=='1')
                    {
                        pret_pizza_custom+=17;
                    }
                    else if(key_dimensiune=='2')
                    {
                        pret_pizza_custom+=24;
                    }
                    else if(key_dimensiune=='3')
                    {
                        pret_pizza_custom+=31;
                    }
                    do
                    {
                        cout<<"\n\nAlegeti tipul de blat: (1-Clasic/ 2-Pufos/ 3-Italian)";
                        key_tip_blat=getch();

                    }
                    while(key_tip_blat!='1' && key_tip_blat!='2' && key_tip_blat!='3');
                    if(key_tip_blat=='1') //blat clasic
                    {
                        p[7].setTip_blat('c');
                    }
                    else if(key_tip_blat=='2') //blat pufos
                    {
                        p[7].setTip_blat('p');
                    }
                    else if(key_tip_blat=='3') //blat italian
                    {
                        p[7].setTip_blat('i');
                    }
                    p[7].setPret(pret_pizza_custom);

                    system("cls");
                    i_for_adresa=0;
                    for(list<Adresa>::iterator iter=a.begin(); iter!=a.end(); iter++)
                    {
                        cout<<++i_for_adresa<<". Localitatea "<<(*iter).getLocalitate()<<", strada "<<(*iter).getStrada()<<", numar "<<(*iter).getNumar_strada()<<", bloc "<<(*iter).getBloc()<<", scara "<<(*iter).getScara()<<", apartament "<<(*iter).getApartament()<<"\n";
                    }
                    cout<<"\nAlegeti adresa livrarii.";
                    key_useless=getch();
                    system("cls");
                    cout<<"Sumar comanda:\n\n1x Pizza "<<p[7].getNume()<<"\n  "<<p[7].AreMozzarella()<<"\n  Tip blat: "<<p[7].TipulDeBlat()<<"\n\nTotal comanda: ";
                    setcolor(11);
                    cout<<p[7].getPret()<<" Lei";
                    setcolor(7);
                    cout<<"\n\nApasati orice tasta pentru a plasa comanda.";
                    key_useless=getch();
                    system("cls");
                    cout<<"Pizza comandata cu succes! Timp aproximativ de livrare: "<<rand() % 55 + 29<<" de minute";
                    cout<<"\n\nApasati orice tasta pentru a continua.";
                    key_useless=getch();
                    meniu();

                }
                else
                {
                    system("cls");
                    cout<<"Trebuie sa va autentificati si sa adaugati cel putin o adresa pentru a plasa o comanda.\n\nApasati orice tasta pentru a continua.";
                    key_useless=getch();
                    meniu();
                }
            }
            else if (key_meniu=='4') //CONT NOU
            {
                system("cls");
                /*string nume,prenume,parola,email;
                cout<<"Nume: ";
                cin>>nume;
                c[1].setNume(nume);
                cout<<"Prenume: ";
                cin>>prenume;
                c[1].setPrenume(prenume);
                cout<<"E-mail: ";
                cin>>email;
                c[1].setEmail(email);
                cout<<"Parola: ";
                cin>>parola;
                c[1].setParola(parola);*/
                cin>>c[1];
                cout<<"\nCont creat cu succes!\n\nApasati orice tasta pentru a continua.";
                numar_conturi++;
                key_useless=getch();
                meniu();
            }
            else if (key_meniu=='5')  //ADAUGARE ADRESA
            {
                system("cls");
                string localitate,bloc;
                char *strada = new char[100];
                int numar_strada,apartament;
                char scara;
                cout<<"Localitate (fara spatii intre cuvinte): ";
                cin>>localitate;
                adresa_aux.setLocalitate(localitate);
                cout<<"Strada: ";
                cin.get();
                cin.getline(strada,100);
                adresa_aux.setStrada(strada);
                cout<<"Numarul strazii (un singur numar intreg): ";
                cin>>numar_strada;
                adresa_aux.setNumar_strada(numar_strada);
                cout<<"Bloc (fara spatii): ";
                cin>>bloc;
                adresa_aux.setBloc(bloc);
                cout<<"Scara (un singur caracter): ";
                cin>>scara;
                adresa_aux.setScara(scara);
                cout<<"Apartament (un singur numar intreg): ";
                cin>>apartament;
                adresa_aux.setApartament(apartament);
                numar_adrese++;
                i_adresa++;
                a.push_back(adresa_aux);
                cout<<"\nAdresa salvata cu succes!\n\nApasati orice tasta pentru a continua.";
                key_useless=getch();
                meniu();
            }
            else if(key_meniu=='3')  //CONT EXISTENT
            {
                if(autentificat==true)
                {
                    system("cls");
                    cout<<"Trebuie sa va delogati de pe contul curent pentru aceasta actiune.";
                    cout<<"\n\nApasati orice tasta pentru a continua.";
                    key_useless=getch();
                    meniu();
                }
                else
                {
                    string email_5,parola_5;
                    bool email_existent=false;
                    system("cls");
                    cout<<"E-mail: ";
                    cin>>email_5;
                    for(int i=1; i<=numar_conturi; i++)
                    {
                        if(c[i].getEmail()==email_5)
                        {
                            email_existent=true;
                            i_email_existent=i;
                        }
                    }
                    if(email_existent==false)
                    {
                        cout<<"\n\nAceasta adresa de e-mail nu apartine niciunui cont.\n\nApasati orice tasta pentru a continua.";
                        key_useless=getch();
                        meniu();
                    }
                    else
                    {
                        cout<<"\nParola: ";
                        cin>>parola_5;
                        if(parola_5==c[i_email_existent].getParola())
                        {
                            cout<<"\n\nAutentificare reusita.\n\nApasati orice tasta pentru a continua.";
                            autentificat=true;
                            key_useless=getch();
                            meniu();
                        }
                        else
                        {
                            cout<<"\n\nParola gresita.\n\nApasati orice tasta pentru a continua.";
                            key_useless=getch();
                            meniu();
                        }
                    }
                }
            }
            else if(key_meniu=='6')  //VIZUALIZARE ADRESE
            {
                system("cls");
                if(numar_adrese==0)
                {
                    cout<<"Momentan nu aveti nicio adresa salvata.\n\nApasati orice tasta pentru a continua.";
                    key_useless=getch();
                    meniu();
                }
                else
                {
                    i_for_adresa=0;
                    for(list<Adresa>::iterator iter=a.begin(); iter!=a.end(); iter++)
                    {
                        cout<<++i_for_adresa<<". Localitatea "<<(*iter).getLocalitate()<<", strada "<<(*iter).getStrada()<<", numar "<<(*iter).getNumar_strada()<<", bloc "<<(*iter).getBloc()<<", scara "<<(*iter).getScara()<<", apartament "<<(*iter).getApartament()<<"\n";
                    }
                    cout<<"\nApasati orice tasta pentru a continua.";
                    key_useless=getch();
                    meniu();
                }
            }
        }
    }
    return 0;
}
