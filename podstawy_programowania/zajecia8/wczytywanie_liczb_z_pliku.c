#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE *fp=fopen("liczby.txt", "w+r+");
    int tab[]={2,5,2,57,3,8,54,14,2,17};
    if (fp==NULL) {
        printf ("plik niedostepny\n");
        exit(1);
    }
    int i=0;
    float suma=0,a;
    for (i=0; i<10; ++i)
    {
        fprintf(fp, "%d ", tab[i]);
    }
    /*for (i=0; tab[i]; ++i)
    {
        fscanf(fp, "%d", &a);
        suma+=a;
    }
    printf("%d", suma);*/
    while (fscanf(fp, "%f", &a)==1)
    {
        suma+=a;
        i++;
    }
    printf("%f", suma/i);
    fclose(fp);
    return 0;
}
