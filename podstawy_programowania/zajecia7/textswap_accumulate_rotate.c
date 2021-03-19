#include <stdio.h>

}

int rotate (int *a, int *b, int *c)
{
    int tmp=*a;
    *a=*b;
    *b=*c;
    *c=tmp;


}
void swapText(char *text1, char *text2)
{
    int tmp;
    int i=0;
    while (text1[i])
    {
        tmp=text1[i];
        text1[i]=text2[i];
        text2[i]=tmp;
        ++i;
    }

}
int accumulate(int *a, int *b)
{
    int suma=0;
    for (; a!=b; a++)

    {

        suma+=*a;
    }
    return suma;
}
int main ()
{
    int a=1, b=5, c=3;
    rotate(&a, &b, &c);
    printf("%d%d%d",a,b,c);
    char t1[]="hello";
    char t2[]="world";
    swapText(t1, t2);
    printf("%s %s", t1, t2);
    int tab[]={1,2,3,4,5};
    int *a=tab;
    int *b=&tab[4];
    int wynik=accumulate(a, b);
    printf("%d", wynik);

    return 0;
}
