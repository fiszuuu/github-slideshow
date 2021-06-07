#include <stdio.h>
#include <stdbool.h>

#define n 100

struct el_kol{
    int prio;
    int value;
};

struct el_kol arr[n];
int end = 0;
size_t quantity = 0;

bool push (int prio, int value){
    if (end >= n) return false;
    quantity++;
    arr[end].value = value;
    arr[end++].prio = prio;
    return true;
}

int pop ()
{
    if (quantity == 0) return -1;
    quantity--;
    int index_of_max = 0;
    for (int i = 1; i < n; ++i){
        if (arr[i].prio > arr[index_of_max].prio){
            index_of_max = i;
        }
    }
    int result = arr[index_of_max].value;
    for (int i = index_of_max; i < n-1; ++i){
        arr[i] = arr[i+1];
    }
    return result;

}


int main (){
    push(1, 1);
    push (2, 2);
    push (1, 3);
    printf("%d ", pop());
    printf("%d ", pop());
    push (10, 4);
    push (100, 5);
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());
    return 0;
}