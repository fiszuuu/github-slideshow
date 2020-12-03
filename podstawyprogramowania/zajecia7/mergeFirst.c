#include <stdio.h>

int *mergeFirst(int *tab1, int *tab2, int N)
{
    int *tab=malloc(2*N*sizeof(int));
    int i,j;
    for (i=0; i<N; ++i)
    {
        tab[2*i]=tab1[i];
        tab[2*i+1]=tab2[i];
    }
    return tab;
}

int main ()
{
    int A[]={1,2,3,4,5,6,7,8,9,10};
    int B[]={10,9,8,7,6,5,4,3,2,1};
    int n=5;
    int *tab=mergeFirst(A, B, n);
    for (int i=0; i<2*n; ++i)
    {
        printf("%d ", tab[i]);
    }
    return 0;
}
