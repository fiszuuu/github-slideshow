#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct wyniki{
        int ilosc;
        double x1;
        double x2;
    };
struct wyniki fun(int a, int b, int c)
{
    double delta=b*b-4*a*c;
    struct wyniki rownanie;
    if (delta<0)
    {
        rownanie.ilosc=0;
    }
    if (delta==0)
    {
        rownanie.x1=-b/(2.*a);
        rownanie.ilosc=1;
    }
    if (delta>0)
    {
        rownanie.x1=(-b-sqrt(delta))/(2.*a);
        rownanie.x2=(-b+sqrt(delta))/(2.*a);
        rownanie.ilosc=2;
    }
    return rownanie;
}
int main ()
{
    int a=1, b=0, c=-2;
    struct wyniki wyniki=fun(a,b,c);
    printf ("jest %d rozwiazan:\n %.2lf %.2lf", wyniki.ilosc, wyniki.x1, wyniki.x2 );

    return 0;
}