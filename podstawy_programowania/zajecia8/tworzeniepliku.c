#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE *fp;
    char tekst[] = "kiedys dalbym sobie reke uciac";
    fp=fopen("pazura.txt", "w")
    if (fp==NULL) {
        printf ("Nie moge otworzyć pliku\n");
        exit(1);
    }
    fprintf (fp, "%s", tekst);
    fclose (fp);

    return 0;
}
