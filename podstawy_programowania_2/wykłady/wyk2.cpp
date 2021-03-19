#include <iostream>


using namespace std;

//STOS
//funkcje wykonują sie na stosie od sufitu do podlogi
void min_max (int tab[], int n, int & min, int & max)
{
    int i;
    max=min=tab[0];
    for (i=0; i<n; ++i)
    {
        if (tab[i]>max) max=tab[i];
        if (tab[i]<min) min=tab[i];
    }
}
int main ()
{
    /*int x=7;
    int&r1=x;
    r1++;
    cout<<r1<<endl;*/
    int tab[]={1,2,3,4,5,2153,-1};
    int max, min;
    int & r1=max;
    int & r2=min;
    min_max(tab, 7, r2, r1);
    cout << min <<endl;
    cout << max <<endl;
    return 0;
}