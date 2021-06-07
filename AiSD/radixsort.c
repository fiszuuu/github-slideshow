#include <stdio.h>
#include <ctime>
#include <cstdlib>

#define N 100

int power (int a, int x){
    if (x == 0) return 1;
    int exp = a;
    for (int i = 0; i < x - 1; ++i)
        a *= exp;
    return a;
}
void print_arr (int *tab, int n){
    for(int i=0;i<n;i++) 
        printf("%d ", tab[i]); 
    printf ("\n");
}
void bubblesort_radix(int * tab, int n, int d){
    int exp = power(10, d);
    //printf ("%d\n", exp);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (tab[i]%exp < tab [j] % exp){
                int tmp = tab[i];
                tab[i] = tab [j];
                tab[j] = tmp;
            }
        }
    }
}
void bubblesort(int * tab, int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (tab[i] < tab [j]){
                int tmp = tab[i];
                tab[i] = tab [j];
                tab[j] = tmp;
            }
        }
    }
}

void radix_count_sort (int *arr, int n, int d){
    int arr_count[10];
    int * tmp = arr;
    //print_arr(tmp, n);
    for (int i = 0; i < 10; ++i)
        arr_count[i] = 0;
    for (int i = 0; i < n; ++i){
        arr_count[(tmp[i]%power(10, d))/power(10,d-1)]++;
    }
    for (int i = 1; i < 10; ++i){
        arr_count[i]+=arr_count[i-1];
    }
    //print_arr(arr_count, 10);
    for (int i = 0; i < n; ++i){
        tmp [arr_count[(tmp[i]%power(10, d))/power(10,d-1)]] = tmp[i];
        arr_count[(tmp[i]%power(10, d))/power(10,d-1)]--;
    }
}


void radixsort(int * arr, int d){
    for (int i = 1; i < d; ++i){
       bubblesort_radix(arr, 5, i);
    }
}


int main (){
    int arr[] = {2311, 5122, 2134, 6012, 3459};
    radix_count_sort(arr, 5, 1);
    //radixsort(arr, 4);
    print_arr(arr, 5);
    //printf ("%d", power(16, 2));
    return 0;
}