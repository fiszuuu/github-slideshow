#include <stdio.h>
#include <ctime>
#include <cstdlib>

#define N 10
struct list_element{
    int value;
    struct list_element * next;
};
void swap(struct list_element *a, struct list_element *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

void insertAtTheBegin(struct list_element **start_ref, int value)
{
    struct list_element *ptr1 = (struct list_element*)malloc(sizeof(struct list_element));
    ptr1->value = value;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}
void list_sort(struct list_element *start)
{
    int swapped, i;
    struct list_element *ptr1;
    struct list_element *lptr = NULL;
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->value > ptr1->next->value)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  



void print_arr (int *tab, int n){
    for(int i=0;i<n;i++) 
        printf("%d ", tab[i]); 
    printf ("\n");
}

void bucketsort(int * arr, int n){
    struct list_element ** arr_list;
    arr_list = (struct list_element**)malloc (sizeof(struct list_element**) * 10);
    for (int i = 0; i < n; ++i){
        arr_list[arr[i] / 10]->value = arr[i];
        arr_list[arr[i] / 10] = arr_list[arr[i] / 10] -> next;
    }
    for (int i = 0; i < 10; ++i){
        list_sort(arr_list[i]);
    }
    
    for (int i = 0, j = 0; i < 10; ++i){
        struct list_element * ptr = arr_list[i];
        while (ptr){
            arr[j] = ptr->value;
            j++;
            ptr = ptr->next;
        }
    }
}

int main (){
    int tab [] = {12, 51, 53, 65, 23, 90, 56, 59};
    bucketsort(tab, 8);
    print_arr(tab, 8);
}