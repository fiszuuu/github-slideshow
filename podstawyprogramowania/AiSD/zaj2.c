#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// nie do końca działa

struct list_element
    {
        struct list_element *next;
        int value;
    };


int main ()
{


    struct list_element *start[100];
    struct list_element *end[100];

    int value[10]={5, 8, 3, 5, 1, 19, 7, 8, 1, 2};

    for (int i=0; i<100; ++i)
    {
        start[i]=0;
        end[i]=0;
    }
    struct list_element *p;

    for (int i=0; i<10; i++)
    {
        p= (struct list_element*)malloc(sizeof(struct list_element));
        p->value = value[i];
        p->next = 0;

        if (start[value[i]]==0)
        {
            start[value[i]]=p;
            end[value[i]]=p;
        }
        else 
        {
            end[value[i]]-> next =p;
            end[value[i]] = p;
        }
    }
    struct list_element *p0;
    int i;
    for (i=0 ; start[i]==0; i++);
    p = end[i];
    p0= start[i];
    for (int i=0; i<100; ++i)
    {
        if(start[i]!=0)
        {
            p->next = start[i];
            p = end[i];
        }
    }
    for (p=p0; p!=0; p=p->next)
    {
        printf("%d ", p->next);
    }
    return 0;
}
