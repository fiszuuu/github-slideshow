

void swap (int *a, int *b)
{
    int *tmp = a;
    a = b;
    b = tmp;

}

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
/*int main ()
{
    //test_komora_wypisz();
    //test_komora_odczyt_spacje();
    //test_komora_odczyt();
    //test_czy_przecina();
    test_czy_losowe_przecina();
    //moj_test_przecinania();
    Komora k(1,2,3,6,7,8);
    return 0;
}*/