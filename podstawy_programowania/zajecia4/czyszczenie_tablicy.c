#include <stdio.h>
#include <string.h>

#define N 4
void czyszczenie (int tab[])
{
    int i;
    for (i=0; i<N; ++i)
    {
        tab[i]=0;
    }

}

int main ()
{
    int tab[N], i;
    for (i=0; i<N; ++i)
    {
        scanf("%d", &tab[i]);
    }
    czyszczenie(tab);
    for (i=0; i<N; ++i)
    {
        printf ("%d ", tab[i]);
    }
    return 0;
}