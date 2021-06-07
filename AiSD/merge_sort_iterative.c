#include <stdio.h>
#include <ctime>
#include <cstdlib>


#define N 1000000

int tmp_arr[N];

void merge (int arr[], int left, int middle, int right){
    int i = left; int j = middle +1;
    for (int k = left; k < right +1; ++k){ // czy na pewno +1
        if (i <= middle){
            if (j <= right){
                if (arr[j] > arr[i]){
                    tmp_arr[k] = arr[i];
                    i++;
                }
                else {
                    tmp_arr[k] = arr[j];
                    j++;
                }
            }   
            else {
                tmp_arr[k] = arr[i];
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
void print_arr (int *tab, int n){
    for(int i=0;i<n;i++) 
        printf("%d ", tab[i]); 
    printf ("\n");
}

void merge_iter (int tab[N],  int n){

    int i, j, k, poczatek_podciagu, dlugosc_podciagu;
    for (dlugosc_podciagu = 1; dlugosc_podciagu < n; dlugosc_podciagu *= 2){
        //printf ("%d\n", dlugosc_podciagu);
        for (i = 0; i < n ; i += dlugosc_podciagu*2){
            int middle = i + dlugosc_podciagu -1;
            int end = middle + dlugosc_podciagu;
            if (end > n) end = n - 1;
            merge (tab, i, middle, end);
            //print_arr(tab, n);
        }
        //printf ("\n");
    }
}


int main (){
    int tablica[N]; 
    srand(time(NULL));
    for (int i = 0; i < N; ++i){
        tablica[i] = rand()%1000;
    }
    merge_iter(tablica, N); 
    //print_arr(tablica, N);
    for (int i = 999900; i < N; ++i)
        printf("%d ", tablica[i]); 
    printf ("\n");
    return 0;
}

