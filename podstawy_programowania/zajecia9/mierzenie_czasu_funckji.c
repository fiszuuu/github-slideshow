#include <stdio.h>
#include <time.h>

int powolna (int *wsk1, int *wsk2)
{
    clock_t start=clock();
    for (int i=0; i<10000; ++i)
    {
    }
    int suma=*wsk1+*wsk2;
    clock_t stop=clock();
    return stop-start;
}

int main ()
{
    int a=5, b=1310;
    int *w1=&a;
    int *w2=&b;

    printf("%d", powolna(w1, w2));
    return 0;
}
