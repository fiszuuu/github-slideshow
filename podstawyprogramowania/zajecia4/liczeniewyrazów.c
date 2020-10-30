#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10000
int countwords (char a[])
{
    int i=0, licznik=0;
    for (; i<strlen(a); ++i)
    {
        if (a[i]==' ')
        licznik++;
    }
    return ++licznik;
}

int main ()
{
    char tekst[N];
    int i=0;
    gets (tekst);
    printf ("%s\n", tekst);
    int licznik=countwords (tekst);
    printf ("powyzszy tekst ma %d slow", licznik);
    return 0;
}
