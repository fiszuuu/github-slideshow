#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>

using namespace std;


void swap (int *a, int *b)
{
    int *tmp = a;
    a = b;
    b = tmp;

}


//KLASA KOMORA

class Komora{
public:
    int x1;
    int y1;
    int z1;
    int x2;
    int y2;
    int z2;
    Komora(int _x1=0,int _y1=0,int _z1=0,int _x2=0, int _y2=0,int _z2=0)
        :x1(_x1),y1(_y1),z1(_z1),x2(_x2),y2(_y2),z2(_z2)
    {
        normalizuj();
    }

    void normalizuj();
    bool czy_przecina(const Komora&other)const;
    string to_string()const;
    ostream& wypisz(ostream&os)const;
    istream& wczytaj_ze_spacjami(istream&is);

    /*
     * Docelowa wersja, nawiasy i przecinki mogą łączyć się z liczbami
     * wczytaj w formacie (x1 y1 z1,x2 y2 z2)
     *
     */
    istream& wczytaj(istream&is);
    void losuj(int xmin,int ymin,int zmin,int xmax,int ymax,int zmax);
    void przesun(int dx,int dy,int dz);
    int objetosc()const;
};

void Komora::normalizuj()
{
   if (x2 < x1) swap(x2, x1);
   if (y2 > y1) swap(y1, y2);
   if (z2 > z1) swap(z1, z2);
}
bool Komora::czy_przecina(const Komora&other)const
{
    if ((this->z1 <= other.z2 || other.z1 <= this->z2) || (this->y1 <= other.y2 || other.y1 <= this->y2) || (this->x1 >= other.x2 ||  other.x1 >= this->x2))
    {
        return false;
    }
    return true;
}
string Komora::to_string()const
{
    ostringstream os;
    os << "( " << x1 << " " << y1 << " " << z1 << " , " << x2 << " " << y2 << " " << z2 << " )";

    //użyj innej metody do wypisania na strumień ostringstream - zapisu do stringu 
    return os.str();
}
ostream& Komora::wypisz(ostream&os)const
{
   os << "( " << x1 << " " << y1 << " " << z1 << " , " << x2 << " " << y2 << " " << z2 << " )";
   return os;
}
istream& Komora::wczytaj_ze_spacjami(istream &is) 
{
    string s;
    is>>s;
    if(s!="(")is.setstate(ios::failbit);
    is >> x1 >> y1 >> z1 >> s; 
    if (s!=",")is.setstate(ios::failbit);
    is >> x2 >> y2 >> z2 >> s;
    if (s!=")")is.setstate(ios::failbit);
    normalizuj();
    return is;
}
istream& Komora::wczytaj(istream&is){
    string s;

    getline(is,s,','); // wczytaj do przecinka
    int idx = s.find('('); // znajdź nawias
    if(idx==string::npos)
    {
        is.setstate(ios::failbit);
        return is;
    }

    s=s.substr(idx+1); // wydziel fragment po nawiasie
    istringstream iss(s); // utwórz wejściowy strumień z obiektu string
    iss>>x1; // wczytaj współrzędne
    iss>>y1;
    iss>>z1;

    getline(is,s,')'); // wczytaj do nawiasu zamykajacego
    iss.clear();
    iss.str(s);  // przypnij strumień do nowego stringu
    iss >> x2 >> y2 >> z2; // następne współzedne
    if (!iss) 
    {
        is.setstate(ios::failbit);
        return is;
    }
    normalizuj();
    return is;
}
void Komora::losuj(int xmin,int ymin,int zmin,int xmax,int ymax,int zmax)
{
    x1 = rand()%(xmax - xmin) + xmin + 1;
    y1 = rand()%(ymax - ymin) + ymin + 1;
    z1 = rand()%(zmax - zmin) + zmin + 1;    
    do
    {
        x2 = rand()%(xmax - xmin) + xmin + 1;
    }
    while (x1 == x2);
        do
    {
        y2 = rand()%(ymax - ymin) + ymin;
    }
    while (y1 == y2);
        do
    {
        z2 = rand()%(zmax - zmin) + zmin; 
    }
    while (z1 == z2);
    normalizuj();
}
void Komora::przesun(int dx,int dy,int dz)
{
    x1 += dx;
    y1 += dy;
    z1 += dz;
    x2 += dx;
    y2 += dy;
    z2 += dz;
}
int Komora::objetosc()const
{
    return (x2-x1)*(y1-y2)*(z1-z2);
}


void test_komora_wypisz()
{
    Komora k(1,2,3,4,5,6);
    k.wypisz(cout);
}
void test_komora_odczyt_spacje(){
    istringstream is("( 1 2 3 , 4 5 -6 )");
    Komora k;
    k.wczytaj_ze_spacjami(is);
    k.wypisz(cout);
}
void test_komora_odczyt(){
    istringstream is("(1 2 3,4 5 6)(23 24 25,26 27 28)");
    Komora k;
    k.wczytaj(is);
    k.wypisz(cout);
    k.wczytaj(is);
    k.wypisz(cout);
}
void test_czy_przecina(){
    istringstream is("(1 1 6,4 4 3)(2 2 8,6 6 5)");
    Komora k;
    k.wczytaj(is);
    k.wypisz(cout);
    Komora k2;
    k2.wczytaj(is);
    k2.wypisz(cout);
    cout<<"Przecina:"<<k.czy_przecina(k2)<<endl;
}
void test_czy_losowe_przecina(){
    Komora k(1,2,3,4,5,6);
    k.wypisz(cout);
    cout<<endl;
    srand(time(NULL));
    for(int i=0;i<10;i++){
        Komora k2;
        k2.losuj(0, 0, 0 ,5, 6, 6);
        k2.wypisz(cout);
        cout<<" "<<k.czy_przecina(k2)<<endl;
    }
}
void moj_test_przecinania()
{
    Komora k1(1,4,6,4,1,3), k2(2,2,5,5,0,0);
    k1.normalizuj();
    k2.normalizuj();
    k1.wypisz(cout);
    cout<<endl;
    k2.wypisz(cout);
    cout<<endl;

    if (k1.czy_przecina(k2)) cout << "przecina i jest dobrze";
    else cout << "nie przecina co jest popsute";
}
void test_objetosc()
{
    Komora k(3,3,3,1,1,1);
    k.wypisz(cout);
    //cout << k.objetosc;
}
int obj(Komora k)
{
    int x=k.x2-k.x1;
    int y=k.y1-k.y2;
    int z=k.z1-k.z2;
    cout<<x<<" "<<y<<" "<<z<<endl;
    return x*y*z;
}



int index_of_lowest;

class Kretowisko{
public:
    vector<Komora> komory;
 
    bool dodaj(const Komora&k);
    /*
     * Buduje kretowisko losując n komór o współrzednych x, y z zakresu [min,max]
     * Wygenerowane komory należy przesunąć o dx=rand()%scatter, dx=rand()%scatter i dz=0
     * Ponieważ komory są pod ziemią - dla współrzednej z losuj z zakresu -abs(depth) do -1
     */
    void buduj(int n, int min, int max, int depth, int scatter);
 
    /*
     * Zapisz w formacie ( komora1,komora2,komora3,....)
     */
    ostream&wypisz(ostream&os)const;
 
    /*
     * Wczytaj w takim formacie, jak zapisałeś
     */
 
    istream&wczytaj(istream&is);
 
    /*
     * Zwróć całkowitą powierzchnię komór
     */
    int powierzchnia()const;
    /*
     * Zwróć  powierzchnię komór na głębokości depth
     */
    int powierzchnia(int depth)const;
 
    /*
     * Zwróć całkowitą objętość komór
     */
    int objetosc()const;
 
    /*
     * Zwróć objętość komór od -inf do głębokości depth
     * Jest to patrząc formalnie całka powierzchnia(d) delta_d
     * Ale powierzchnia(d) to funkcja odcnikami stała...
     */
    int objetosc(int depth)const;
 
    /*
     * Wszystkie komory są połączone ze sobą. Złośliwy ogrodnik wlał do kretowiska wodę,
     * która rozpłynęła się pomiędzy komoram.
     * Załóż że objętość wlanej wody nie przewyższa sumarycznej objętości komór
     * Oblicz do jakiego poziomu zostaną zalane komory?
     */
    double poziom_wody(double v)const;
 
};
bool Kretowisko::dodaj(const Komora&k){
    for (int i=0; i < komory.size() ;  i++)
    {
        if (k.czy_przecina(komory[i]))
        {
            return false;
        }
    }
    komory.push_back(k);
    return true;
}
void Kretowisko::buduj(int n, int min, int max, int depth, int scatter){
    int i=0;
    if(depth>0)depth*=-1;
    while(i<n){
        Komora k;
        k.losuj(min, min, min, max, max, max);
        int dx=rand()%scatter;
        int dy=rand()%scatter;
        k.przesun(dx, dy, 0);
        if(dodaj(k))i++;
    }
    /*while (i>0)
    {
        
        i--;
    }*/
}
ostream&Kretowisko::wypisz(ostream&os)const{
    os<<'(';
    // ...
    for (int i =0; i < komory.size(); ++i)
    {
        komory[i].wypisz(cout);
        os<<',';
    }
    os<<')';
    return os;
}
istream&Kretowisko::wczytaj(istream&is)
{
    komory.clear(); 
    int c;
    do{
        c=is.get();
        if (!is) return is;
    }while(c!='('); // znajdź '(' ale przerwij, gdy !is
 
    for(;;){
        c=is.get(); 
        // jeżeli koniec pliku lub napotkano ')' to przerwij
        if (c==')') break;
        if (!is) return is;
        if(c=='('){
            // jeżeli napotkano '(', to
            // cofnij znak do strumienia za pomocą unget()
            // wczytaj komorę i dodaj do kretowiska 
            is.unget();
            Komora k;
            k.wczytaj(is);
            dodaj(k);
         }
     }
     return is;
}
int Kretowisko::powierzchnia()const
{
    int S=0;
    for (int i=0; i<komory.size(); i++)
    {
        S+=(komory[i].x2-komory[i].x1)*(komory[i].y1-komory[i].y2);
    }
    return S;
}
int Kretowisko::powierzchnia(int depth)const
{
    int S=0;
    for (int i=0; i<komory.size(); i++)
    {
        if (komory[i].z2 < depth && depth < komory[i].z1)
            S+=(komory[i].x2-komory[i].x1)*(komory[i].y1-komory[i].y2);
    }
    return S;
}
int Kretowisko::objetosc()const
{
    int V=0;
    for (int i=0; i<komory.size(); i++)
    {
        V+=(komory[i].x2-komory[i].x1)*(komory[i].y1-komory[i].y2)*(komory[i].z1-komory[i].z2);
    }
    return V;
}
int Kretowisko::objetosc(int depth)const
{
    int V=0;
    for (int i=0; i<komory.size(); i++)
    {
        if (komory[i].z1 < depth) //gdy cała komora pod zadana glebokością
            V+=abs(komory[i].x2-komory[i].x1)*abs(komory[i].y1-komory[i].y2)*abs(komory[i].z1-komory[i].z2);
        if (komory[i].z2 < depth && depth < komory[i].z1) //gdy tylko część komory pod zdana głębokością
            V+=abs(komory[i].x2-komory[i].x1)*abs(komory[i].y1-komory[i].y2)*abs(depth-komory[i].z2);
    }
    return V;
}
double Kretowisko::poziom_wody(double v)const
{
    int i;
    for (i=0; i < komory.size(); i++)
    {
        if (komory[index_of_lowest].z2 > komory[i].z2)
            index_of_lowest=(int)i;
    }
    for (i=index_of_lowest; i>0; i--)
    {
        if (this->objetosc(i) > v)
        {
            return (double)i-1+((v-this->objetosc(i-1))/this->powierzchnia(i-1));
        }
    }
    return -1;
}

//TESTY
void test_kretowisko_buduj()
{
    Kretowisko X;
    X.buduj(5, 0, 5, 3, 5);
    X.wypisz(cout);
}
void test_kretowisko_wczytaj()
{
    string s="(( 8 15 -5 , 11 14 -7 ) ( 14 13 -4 , 17 11 -8 ) ( 13 7 -3 , 16 4 -4 ) "
             "( 1 6 -7 , 4 4 -10 ) ( 16 20 -4 , 18 19 -10 ) ( 5 16 -7 , 8 14 -8 ) "
             "( 13 11 -3 , 17 10 -5 ) ( 11 20 -2 , 13 18 -7 ) ( 17 14 -5 , 18 12 -8 ) "
             "( 17 18 -4 , 20 16 -9 ) )";
    istringstream is(s);
    Kretowisko k;
    k.wczytaj(is);
    k.wypisz(cout);
}
void test_kretowisko_buduj_zapisz_wczytaj_wypisz()
{
    srand(0);
    Kretowisko k;
    string s, s2;
    k.buduj(5, 0, 5, 3, 3);
    ostringstream os;
    k.wypisz(os);
    ostringstream os2;
    k.wypisz(os2);
    s = os.str();
    s2 = os.str();
    if (s==s2)
        cout<<"jest fajnie";

}
void test_jedna_komora()
{
    cout<<"TESTING poziom_wody() dla jednej komory"<< endl;
    Kretowisko k;
    k.buduj(1,0,5,3,3);
    k.komory[0].wypisz(cout)<<endl;
    for (int i=k.komory[0].z2; i<k.komory[0].z1 || i<k.komory[1].z1; i++)
    {
        cout <<"powierzchnia: "<< k.powierzchnia(i)<<endl;
        cout <<"objętość: "<< k.objetosc(i) <<endl; //objęrość w funckji wychodzi dobra ale z jakiegoś powodu zła wyswietla TODO: funckja liczacą objętość dla komory zjednym kretowiskiem
    }
}
void test_dwie_komory()
{
    cout<<"TESTING poziom_wody() dla dwóch komór"<< endl;
    Kretowisko k;
    k.buduj(2, 0, 5, 5, 3);
    k.komory[0].wypisz(cout)<<endl;
    k.komory[1].wypisz(cout)<<endl;
    for (int i=k.komory[0].z2; i<k.komory[0].z1 || i<k.komory[1].z1; i++)
    {
        cout<<"na głębokości "<<i<<endl;
        cout <<"powierzchnia: "<< k.powierzchnia(i)<<endl;
        cout <<"objętość: "<< k.objetosc(i) <<endl; //objęrość w funckji wychodzi dobra ale z jakiegoś powodu zła wyswietla TODO: funckja liczacą objętość dla komory zjednym kretowiskiem
    }
}
void objetosc_test_1()
{
    Kretowisko k;
    k.buduj(1,0,5,3,3);
    k.komory[0].wypisz(cout)<<endl;
    cout <<"objetosc: "<< k.objetosc(3)<<endl;
}


int main ()
{
    srand(time(NULL));
    //test_kretowisko_buduj();
    //test_kretowisko_wczytaj();
    //void test_kretowisko_buduj_zapisz_wczytaj_wypisz();
    //test_jedna_komora();
    //objetosc_test_1();
    //test_dwie_komory();
    return 0;
}