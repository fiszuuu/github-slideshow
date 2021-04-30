#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct el_listy
{
    struct el_listy *nast, *pop;
    double w;
};

struct el_listy2
{ 
    int nast, pop; 
    int w; 
}; 
int main ()
{
    srand(time(NULL));
    /*struct el_listy * pierwszy;
    pierwszy = malloc(sizeof(struct el_listy));
    pierwszy->w = 10;
    pierwszy -> nast = malloc(sizeof(struct el_listy));
    pierwszy->nast->w = 15; 
    pierwszy->nast->pop = pierwszy; 
    pierwszy->nast->nast = 0; 
    pierwszy->pop = 0; */
    struct el_listy2 tab[100];
    for (int i=0; i<100; ++i)
    {
        tab[i].w = rand()%100; 
        tab[i].pop = i-1;
        if (i != 99)
            tab[i].nast = i+1; 
        else 
            tab[i].nast = -1;
    }
    for (int i=0; i < 100; ++i)
    {
        printf("%d ", tab[i].w);
    }
    printf("\n");
    return 0;
}