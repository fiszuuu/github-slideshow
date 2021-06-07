#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct el_listy
{
    struct el_listy *nast, *pop;
    double w;
};

int main ()
{
    srand(time(NULL));
    struct el_listy * pierwszy;
    pierwszy = (struct el_listy *)malloc(sizeof(struct el_listy));
    pierwszy->w = 10;
    struct el_listy * kolejny = pierwszy -> nast = (struct el_listy *)malloc(sizeof(struct el_listy));
    pierwszy->nast->w = 15; 
    pierwszy->nast->pop = pierwszy; 
    pierwszy->nast->nast = 0; 
    pierwszy->pop = 0; 

    printf ("%f", kolejny->w);
    return 0;
}