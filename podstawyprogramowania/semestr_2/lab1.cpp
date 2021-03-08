#include <iostream>

using namespace std;

const int N=10;

class Fibo1{
    int*tab;
    int n;
    public:
      void init(int _n);
      void destroy();
      void fill();
      void print();
};
class Fibo{
    int*tab;
    int n;
    public:
      Fibo (int _n)
    {
        if (n<=0)
        {
        tab=0;
        n=0;
        return;
        }
        n=_n;
        tab = new int[n];
    };
      void print();
      void fill();
    ~Fibo()
    {
    if(tab)delete [] tab;
    };
};
void fibo1()
{
    int tab[N], i;
    tab[0]=1, tab[1]=1;
    for (i=2; i<N; ++i)
    {
        tab[i]=tab[i-2]+tab[i-1];
    }
    for (i=0; i<N; ++i)
    {
        cout<<tab[i]<<" ";
    }
}
void fibo2 (int n)
{
    int *tab= new int[n];
    int i;
    tab[0]=1, tab[1]=1;
    for (i=2; i<n; ++i)
    {
        tab[i]=tab[i-2]+tab[i-1];
    }
    for (i=0; i<n; ++i)
    {
        cout<<tab[i]<<" ";
    }
    delete [] tab;
}
void Fibo1::init (int _n)
{
    n=_n;
    if (n<=0)
    {
        tab=0;
        n=0;
        return;
    }
    tab= new int[n];
}
void Fibo1::destroy()
{
    if(tab)delete [] tab;
}
void Fibo1::fill()
{
    int i;
    if (tab==0) return;
    tab[0]=1, tab[1]=1;
    for (i=2; i<n; ++i)
    {
        tab[i]=tab[i-2]+tab[i-1];
    }
}
void Fibo::fill()
{
    int i;
    if (tab==0) return;
    tab[0]=1, tab[1]=1;
    for (i=2; i<n; ++i)
    {
        tab[i]=tab[i-2]+tab[i-1];
    }
}
void Fibo1::print()
{
    int i;
    if (tab==0) return;
    for (i=0; i<n; ++i)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}
void Fibo::print()
{
    int i;
    if (tab==0) return;
    for (i=0; i<n; ++i)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}
void test_fibo1(int n)
{
    Fibo1 fibo;
    fibo.init(n);
    fibo.fill();
    fibo.print();
    fibo.destroy();
}
void test_fibo(int n)
{
    Fibo fibo(n);
    fibo.fill();
    fibo.print();
}
class GeoSequence
{
    double *tab;
    int n_g;
    double first, q;
    public:
        GeoSequence (int _n_g)
        {
            if (n_g<=0)
            {
                tab=0;
                n_g=0;
                return;
            }
            n_g=_n_g;
            tab= new double[n_g];
        }
        void print()
        {
            int i;
            if (tab==0) return;
            for (i=0; i<n_g; ++i)
            {
                cout<<tab[i]<<" ";
            }
            cout<<endl;
        }
        void fill (double _q, double _first)
        {
            if (tab==0) return;
            int i;
            first=_first;
            q=_q;
            tab[0]=first;
            for (i=1; i<n_g; ++i)
            {
                tab[i]=tab[i-1]*q;
            }
        }
        ~GeoSequence ()
        {
        if (tab)
        delete [] tab;
        }

};
void geotest(int n, double q, double first)
{
    GeoSequence hey(n);
    hey.fill(q, first);
    hey.print();
}
int main ()
{
    /*fibo1();
    cout<<endl;
    fibo2(10);
    cout<<endl;
    test_fibo1(10);
    cout<<endl;*/
    test_fibo(9);
    geotest(7, 0.5, 16);
    return 0;
}