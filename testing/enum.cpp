#include <iostream>
#include <fstream>


using namespace std;

enum Months
{
    January,
    February,
    March,
    April,  
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

int main ()
{
    Months yoo;
    yoo = January;
    yoo++;
    cout << yoo;
    cout << endl;
    return 0;
}