#include <iostream>


using namespace std;

const int  n=10;
const long long int N=100000000;
int main ()
{
    double arr[n];
    srand(time(NULL));
    for (int i = 0; i<N; i++)
    {
        arr[rand()%n]++;
    }
    for (int i=0; i<n; i++)
    {
        cout << arr [i]/N << " ";
    }
    cout << endl;
    return 0;
}