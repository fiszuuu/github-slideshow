#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

#define N 1000


int count_arr[N];


void countsort(int arr[], int arr_size, int result_arr[]){
    int i;
    for (i = 0; i < N; ++i)
        count_arr[i] = 0;
    for (i = 0; i < arr_size; ++i)
        count_arr[arr[i]]++;
    for (i = 1; i < N; ++i)
        count_arr[i] += count_arr[i-1];
    for (int i = 0; i < arr_size; ++i){
        result_arr[count_arr[arr[i]]] = arr[i];
        count_arr[arr[i]]--;
    }
}

void print_arr (int *tab, int n){
    for(int i=0;i<n;i++) 
        printf("%d ", tab[i]); 
    printf ("\n");
}

int main (){
    srand(time(NULL));
    const int n = 1000000;
    int arr[n], result[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand()%N;
    countsort(arr, n, result);
    print_arr(result, n);
}