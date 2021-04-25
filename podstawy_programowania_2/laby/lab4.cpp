#include <iostream>
#include <fstream>


using namespace std;
class Student{
public:
    int indeks;
    string imie;
    string nazwisko;
    bool skreslony=false;
    string grupa;
    /*
     * Czytaj dane z istream. Załóż, że pola są oddzielone znakiem tabulacji
     * */
    void read(istream&is);
    /*
     * Zapisz dane do istream. Oddzielaj pola znakiem tabulacji. Nie dodawaj endline
     * */
    void write(ostream&os)const;
};

void Student::read(istream &is) {
    is >> indeks;
    is >> imie;
    is >> nazwisko;
    is >> skreslony;
    is >> grupa;
}

void Student::write(ostream &os) const {
    os << indeks << '\t';
    os << imie << '\t';
    os << nazwisko << '\t';
    os << skreslony << '\t';
    os << grupa;
}

void test_read_write(){
    ifstream is("studenci_isi-2021.csv");
    if(!is){
        cerr<<"Błąd otwarcia pliku"<<endl;
        return;
    }
    string header;
    // czytaj nagłówek za pomocą getline()
    getline (is, header);
    cout<<header<<endl;
    while(is) {
        Student st;
        st.read(is);
        if (!is) break;
        st.write(cout);
        cout << endl;
    }
}
/*Klasa StudentList
Zadeklaruj klasę StudentList. Zawiera ona wskaźnik do tablicy obiektów typu Student. Tablica ma pojemność capacity. W danym momencie zawiera count studentów.

Jeżeli ktoś chce, może zadeklarować tablicę, jako vector<Student>. Ale musi rozwiązać problem odwzorowania:
ustawiania capacity na metodę klasy vector
podobnie: dodawania elementu
usuwania i-tego elementu wektora.
Wtedy będzie to zastosowanie dwóch mechanizmów kompozycji i delegacji*/
class StudentList{
    Student*tablica=0;
    int count=0;
    int capacity=0;
public:
    StudentList(int cap=100):capacity(0),tablica(0) {
        if (cap > 0) {
            capacity = cap;
            tablica = new Student[cap];
        }
    }
    ~StudentList(){
        if(tablica)delete []tablica;
    }

    int getCount()const{
        return count;
    }
    bool add(const Student&st);
    /*
     * Czytaj ze strumienia i dodawaj.
     * Strumień nie ma nagłówka
     * Przerwij, gdy nie uda się odczyt lub zabraknie miejsca
     */
    void read(istream&is);
    /*
     *Zapisuj do strumienia (bez nagłówka)
     */
    void write(ostream&os)const;
    bool skresl(int index){
        for (int i=0; i < count; ++i)
        {
            if (tablica[i].indeks == index)
            {
                tablica[i].skreslony = true;
                return true;
            }
        }
        return false;
    }
    bool reaktywuj(int index){
        for (int i=0; i < count; ++i)
        {
            if (tablica[i].indeks == index)
            {
                tablica[i].skreslony = false;
                return true;
            }
        }    
        return false;
    }
    /*
     * usuń studenta o danym indeksie z tablicy
     * fizycznie usuń obiekt
     */

    bool usun(int index);

    /*
     * Utwórz listęi umieść w niej wszystkich studentów
     * których pole grupa jest równe group
     */
    StudentList selectGroup(const char*group)const;

    /*
     * Utwórz listę i umieść w niej wszystkich studentów
     * którzy spełniają predykat.
     * Predykat jest wskaźnikiem do funkcji boolowskiej, której parametrem jest student
     */

    StudentList select(bool (*pred)(const Student&s))const;
};
bool StudentList::add(const Student&st){
    if(count==capacity)return false;
    tablica[++count] = st;
}
void StudentList::write(ostream&os)const
{
    for(int i=0;i<count;i++)
    {
        tablica[i].write(os);
    }
}
void StudentList::read(istream&is)
{
    while (is)
    {
        Student st;
        st.read(is);
        this->add(st);
        if (!is) break;
    }
}
bool StudentList::usun (int index)
{
    for (int i=0; i<count; ++i)
    {
        if (tablica[i].indeks == index)
        {
            for (int j=i; i<count; i++)
            {
                tablica[j] = tablica [j+1];
            }
            count--;
        }
    }
}
void test_list_read(){
    ifstream is("studenci_isi.csv");
    if(!is){
        cerr<<"Błąd otwarcia pliku"<<endl;
        return;
    }
    string header;
    getline(is,header);
    StudentList st;
    st.read(is);
    st.write(cout);
}
int main ()
{
    //test_read_write();
    test_list_read();
    return 0;
}