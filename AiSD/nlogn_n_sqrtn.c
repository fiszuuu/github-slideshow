#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100
#define range 50
int tmp_arr[N];


void print_arr (int *tab, int n){
    for(int i=0;i<n;i++) 
        printf("%d ", tab[i]); 
    printf ("\n");
}

void merge (int * arr, int left, int middle, int right){
    int i = left, j = middle +1;
    for (int k = left; k < right + 1; ++k){
        if (i <= middle){
            if (j <= right){
                if (arr[i] > arr[j]){
                    tmp_arr[k] = arr[j];
                    j++;
                }
                else {
                    tmp_arr[k] = arr[i];
                    i++;
                }
            }
            else {
                tmp_arr[k] = arr [i];
                i++;
            }
        }
        else {
            tmp_arr[k] = arr[j];
            j++;
        }
    }
    for (int k = left; k < right +1; ++k){
        arr[k] = tmp_arr[k];
    }
}

void merge_sort (int * arr, int n){
    for (int length = 1; length < n; length *= 2){
        printf("%d\n", length);
        for (int i = 0; i < n; i+=length*2){
            int end = i + 2* length - 1;
            int middle = end - length;
            if (end > n) end = n - 1;
            merge (arr, i, middle, end);
            print_arr(arr, n);
        }
        printf ("\n");
    }

}

void bubble_sort (int * tab, int n){
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            if (tab[i] > tab[j]){
                int tmp = tab[j];
                tab[j] = tab [i];
                tab[i] = tmp;
            }
        }
    }
}

void count_sort (int * arr, int n, int result_arr[]){
    int c[range];
    for (int i = 0; i < range; ++i){
        c[i] = 0;
    }
    for (int i = 0; i < n; ++i){
        c[arr[i]]++;
    }
    for (int i = 1; i < range; ++i){
        c[i] += c[i-1];
    }
    for (int i = 0; i < n; ++i){
        result_arr[c[arr[i]]] = arr[i];
        c[arr[i]]--;
    }
}


int main (){
    srand(time(NULL));
    int arr[N], result[N];
    for (int i = 0; i < N; ++i)
        arr[i] = rand()%50;
    print_arr(arr, N);
    // merge(arr, 0, 5, 10);
    // merge_sort(arr, N);
    //bubble_sort(arr, N);
    count_sort(arr, N, result);
    print_arr(result, N);
    //print_arr(arr, N);
    return 0;
}
