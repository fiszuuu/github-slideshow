#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int random(int seed=-1)
    {
        int i,x;
        if (seed==-1)
        {
            srand(time(NULL));
        }
        else
        {
            srand(seed);
        }
        x=rand()%100;
        return x;
    }
int main ()
{
    for (int i=0; i<20; i++)
    {
        cout<<i<<"    ";
        for (int j=0; j<5; j++)
        {
            cout<<random(i)<<" ";
        }
        cout<<endl;
    }
}