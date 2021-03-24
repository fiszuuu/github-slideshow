#include <iostream>

using namespace std;


int main ()
{
    int tab[] = {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49}; 

    int c[100], wynik[20]; 

    int k=100, n = 20, i;  

    for (i = 0; i < k; i++) c[i] = 0; 

    for (i = 0; i < n; i++) c[tab[i]]++; 
    for (i=0; i < n; i++)
    {
        cout << c[tab[i]] << " ";
    }
    cout << endl;
    for (i =1; i < k; i++) c[i] += c[i-1]; 
    for (i=0; i < n; i++)
    {
        cout << c[tab[i]] << " ";
    }
    cout << endl;
    for (i=0; i<n; i++){ 

    wynik[c[tab[i] - 1]] = tab[i]; 

    c[tab[i]]--; 

    }  

    for(i = 0; i<n; i++) printf("%d ", wynik[i]); 
    return 0;
}