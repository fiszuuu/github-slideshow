#include <iostream>

using namespace std;

int main ()
{
    double x1, x2, x3;
    cin >> x1 >> x2 >>x3;
    double x_to_2 = x1 + x2 + x3;
    double x_to_1 = x1*x2 + x2*x3 + x1*x3;
    double x_to_0 = x1*x2*x3;
    cout << "x^2 x^1 x^0 "<<endl;
    cout << " " << x_to_2 <<"   " << x_to_1 << "   " << x_to_0 << endl;
    return 0;
}