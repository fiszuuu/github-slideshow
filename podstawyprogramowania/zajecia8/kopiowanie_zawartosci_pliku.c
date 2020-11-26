#include <stdio.h>


int main ()
{
    FILE *plik, *kopia;
    const char s[100];

    if ((plik=fopen("pazura.txt", "r"))==NULL)
    {
        perror ("plik niedostepny");
        exit(1);
    }
    kopia=fopen("kopia.txt", "w");

    fgets(s, 100, plik);
    fprintf (kopia, "%s", s);

    fclose(plik);
    fclose(kopia);
    return 0;
}
