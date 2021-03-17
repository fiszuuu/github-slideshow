#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdio>

using namespace std;


static int compare (const void* x, const void*y)
{
    if (*(double*)x < *(double*)y) return -1;
    if (*(double*)x == *(double*)y) return 0;
    if (*(double*)x > *(double*)y) return 1;
    //return *(const int*)y - *(const int*)y;
}
class Array{
    double*data;
    int n;
public:
    Array(int size=20):data(0){
        n=(size>=0)?size:0;
        if(n>0)data = new double[n];
    }
    ~Array(){
        if(data)delete data;
    }
        /*
     * wypełnij datalice równomiernie rozłożonymi elementami od start to end
     * Funkcja zwraca false, jeżeli end<start
     * */
    bool linspace(double start=0,double end=1)
    {
        if (end<start) 
        {
            return false;
        }
        int i;
        double r=(end-start)/n;
        data[0]=start+r;
        for (i=1; i<n; ++i)
        {
            data[i]=data[i-1]+r;
        }
        return true;
    };
    /*
     * wypełnij datalice losowymi elementami z zakresu 0-1
     *
     * Wywołanie srand()
     * jeżeli seed == -1 zainicjuj generator liczb pseudolosowych time(0)
     * w przeciwnym wypadku zainicjuj wartością seed
     * */
    void random(int seed=-1)
    {
        int i;
        if (seed==-1)
        {
            srand(time(NULL));
        }
        else
        {
            srand(seed);
        }
        for (i=0; i<n; ++i)
        {
            data[i]=(double)rand()/RAND_MAX;
        }
    };

    /*
     * zapis do strumienia wyjściowego w formacie:
     * n, ciąg n liczb typu double
     */

    void write_formatted(ostream&os)const
    {
        int i;
        os << n << " ";
        for (i=0; i<n; i++)
        {
            os << data[i] << " ";
        }
    };

    /*
     * Zwolnij pamięć
     * Przeczytaj n
     * Przydziel pamięć
     * Przeczytaj liczby
     * */
    void read_formatted(istream&is)
    {
        if (data) 
        {
            delete data;
        }
        int i;
        is >> n;
        data= new double[n];
        for (i=0; i<n; i++)
        {
            is >> data[i];
        }
    };

    /*
     * Dodaj do każdego elementu datalicy wartość v
     */
    void add(double v)
    {
        if (data)
        {
            int i;
            for (i=0; i<n; i++)
            {
                data[i]+=v;
            }
        } 
    };
    /*
     * Pomnóż każdy element datalicy przez wartość v
     */
    void mul(double v)
    {
        if (data)
        {
            int i;
            for (i=0; i<n; i++)
            {
                data[i]*=v;
            }
        }
    };
    void shuffle (int seed = -1)
    {
        int i, j;
        if (seed==-1)
        {
            srand(time(NULL));
        }
        else
        {
            srand(seed);
        }
        for (i=0; i<n/2 ; ++i)
        {
            j = rand()%n;
            if (i!=j)
            {
                double tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    };
    void bubble_sort()
    {
        int i,j;
        for (i=0; i<n; ++i)
        {
            for(j=0; j<n-i; ++j)
            {
                if (data[j] > data[j+1])
                {
                double tmp = data[j+1];
                data[j+1] = data[j];
                data[j] = tmp;
                }
            }
        }
    };

    void quicksort ()
    {
         qsort(data, n, sizeof(double), compare);
    };

};
void print_arr (double arr[], int n)
{
    int i;
    for (i=0; i<n; ++i)
    {
        cout << arr[i];
    }
}
void test_linspace()
{
    Array heya;
    heya.linspace();
    heya.write_formatted(cout);
}
void test_random()
{
    Array heya;
    heya.random();
    heya.write_formatted(cout);
}
void test_mul_add()
{
    Array heya, elko, ema, yoow;
    heya.random();
    heya.add(4);
    heya.write_formatted(cout);
    cout<<endl;
    elko.random();
    elko.add(-0.5);
    elko.mul(20);
    elko.write_formatted(cout);
    cout<<endl;
    ema.linspace(0,100);
    ema.write_formatted(cout);
    cout<<endl;
    yoow.linspace(0,10);
    yoow.mul(-1);
    yoow.write_formatted(cout);
    cout<<endl;
}
void test_file_write(const char*nazwa_pliku)
{
    Array array(100);
    array.linspace();
    ofstream os(nazwa_pliku);
    if(!os)
    {
        cerr<<"ERROR WHILE OPENING FILE: " << nazwa_pliku << endl;
        return;
    }
    array.write_formatted(os);
    os.close();
}
void test_file_read(const char*nazwa_pliku)
{
    Array array(0);
}
void test_quicksort ()
{
    Array tab;
    tab.linspace();
    tab.shuffle();
    tab.write_formatted(cout);
    cout<<endl;
    tab.quicksort();
    tab.write_formatted(cout);
}
void test_save_array_2D(const char*file_name){
    Array *tab = new Array[10];
    int i, j;
    ofstream os(file_name);
    if (!os)
    {
        cerr << "Error while opening file " << file_name << endl;
        return;
    }
    os << 10 << endl;
    for (i=0; i<10; ++i)
    {
        tab[i].random(i);
        tab[i].add(i);
        tab[i].write_formatted(os);
        os << endl;
    }
    os.close();
    delete[]tab;
}
void test_load_array_2D(const char * file_name)
{
    ifstream is(file_name);
    int x, i;
    if (!is)
    {
        cerr << "Error while opening file " << file_name << endl;
        return;
    }
    is >> x;
    cout << x << endl;
    Array *tab = new Array[x];
    for (i=0; i<x; i++)
    {
        tab[i].read_formatted(is);
        tab[i].write_formatted(cout);
    }
    is.close();
    cout<<endl;
}
string load_file(const char*name)
{
    ifstream is(name);
    if(!is){
        cerr<<"Bład otwarcia pliku:"<<name<<endl;
        return "";
    }
    string r;
    for(;;)
    {
        int c = is.get();
        if(c<0)break;
        r += c;
    }
    return r;
}
int main ()
{
    //test_linspace();
    //test_random();
    //test_mul_add();
    //test_quicksort();
    //test_save_array_2D("plik1.txt");
    test_load_array_2D("plik1.txt");
    return 0;
}