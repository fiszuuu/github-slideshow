#include <stdio.h>
#include <string.h>

#define N 1000
void pomin (char tekst[], char wyrzutek)
{
        char tekst2[strlen(tekst)+1];
        int i, j=0;
        for (i=0; i<strlen(tekst); ++i)
        {
            if (tekst[i]!=wyrzutek)
            {
            tekst2[j]=tekst[i];
            j++;
            }
        }
        tekst2[j]=0;
        strcpy (tekst, tekst2);

}


int main ()
{
    char tekst[]={"przedmiot konkretny służący do przekazywania informacji na bazie rozumianego abstrakcyjnie języka"};
    char a;
    printf ("podaj litere ktora chcesz wyrzucic: ");
    scanf ("%c", &a);
    pomin (tekst, a);
    printf ("%s\n", tekst);
    return 0;
}