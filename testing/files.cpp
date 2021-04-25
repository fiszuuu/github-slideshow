#include <iostream>
#include <fstream>

#define N 10
using namespace std;

int main ()
{
    float tab[N];
    /*ifstream os("plik1.txt");
    if(!os)
    {
        cerr<<"ERROR WHILE OPENING FILE"<<endl;
        exit(1);
    }
    for (int i=0; i<N; i++)
    {
        os >> tab[i];
    }
    for (int i=0; i<N; i++)
    {
        cout << tab[i] << " ";
    }
    cout<<endl;
    os.close();*/
    fstream file;
    file.open("cin.txt", fstream::app);
    if (!file)
    {
        cerr<<"ERROR WHILE OPENING FILE"<<endl;
        exit(1);
    }
    int a;
    while (cin>>a)
    {
        if (a=='q')
        {
            break;
        }
        file << a <<endl;
    }
    file.close();
    ifstream file_read("cin.txt");
    for (int i=0; i<N; i++)
    {
        file_read >> tab[i];
    }
    for (int i=0; i<N; i++)
    {
        cout << tab[i] << " ";
    }
    file.close();
    
    return 0;
}