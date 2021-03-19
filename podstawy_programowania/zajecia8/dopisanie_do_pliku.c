#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE *fp=fopen("pazura.txt", "a");
    const char tekst2[]="\ni wiec co...";
    if (fp==NULL) {
        printf ("Nie moge otworzyć pliku\n");
        exit(1);
    }
    fprintf (fp, "%s", tekst2);
    fclose(fp);
    return 0;
}
