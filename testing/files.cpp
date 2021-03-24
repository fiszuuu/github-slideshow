#include <iostream>
#include <fstream>

#define N 10
using namespace std;

int main ()
{
    ifstream os("plik1.txt");
    if(!os)
    {
        cerr<<"ERROR WHILE OPENING FILE"<<endl;
        exit(1);
    }
    float tab[N];
    for (int i=0; i<N; i++)
    {
        os >> tab[i];
    }
    for (int i=0; i<N; i++)
    {
        cout << tab[i] << " ";
    }
    cout<<endl;
    return 0;
}