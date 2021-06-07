#include <stdio.h>

int heap_size = 11; 

int parent(int i) { 
    return i/2; 
} 

int left(int i) { 
    return 2*i; 
} 

int right(int i) { 
    return 2*i + 1; 
} 
//a[parent(i)] >= a[i]; 

 

void heapify(double tab[], int i) { 
    int l = left(i), r = right(i), max_index; 
    double temp; 
    if(l <= heap_size && tab[l]  > tab[i]) { 
        max_index = l; 
    } 
    else { 
        max_index = i; 
    }
    if(r <= heap_size && tab[r] > tab[max_index]) { 
        max_index = r; 
    } 
    if(max_index != i) { 
        temp = tab[i]; 
        tab[i] = tab[max_index]; 
        tab[max_index] = temp;
        heapify(tab, max_index);
}
} 

 

void build_heap(double tab[]) { 
    for(int i = heap_size/2; i >= 1; i--) { 
        heapify(tab, i); 
    }
} 

 

void heap_sort(double tab[], int n) { 
    double temp; 
    heap_size = n; 
    build_heap(tab); 
    for(int i = heap_size; i >= 2; i--) { 
        //swap (tab[1], tab[i]);
        temp = tab[1]; 
        tab[1] = tab[i]; 
        tab[i] = temp; 
        heap_size--; 
        heapify(tab, 1); 
    } 
} 

 

int main() { 
    double tab[21] = {0,1,5,4.36,7,12,17, -11, 8, 0, 86,12, 1, 17, 2, 21, 56,53,-20,10,15}; 
    int n = 20; 
    heap_sort(tab, n); 
    for(int i = 1; i <= n; i++) { 
        printf("%lf ", tab[i]); 
    }
    return 0; 
} 