#include <stdio.h>
#include <stdlib.h>


struct heap_el {
    double value;
    struct heap_el * ojciec, * lewy, * prawy;
};

void wstaw (struct heap_el **root, double value){
    struct heap_el * ptr = * root, * prev = 0;
    struct heap_el * nowy = (struct heap_el*)malloc(sizeof(struct heap_el));
    nowy -> value = value;
    nowy -> lewy = 0;
    nowy -> prawy = 0;
    if (ptr == 0) *root = nowy;
    while (ptr){
        prev = ptr;
        if (ptr->value > value) ptr= ptr -> lewy;
        else ptr = ptr->prawy;
        nowy -> ojciec = prev;
        if (prev == 0) *root = nowy;
        else {
            if (ptr->value > value) prev->lewy = nowy;
            else prev -> prawy = nowy;
        }
}
}

void wypisz (struct heap_el *root){
    if (root == 0){
        printf("LIPAA");
        return;
    }
    printf ("%lf", root -> value);
    wypisz (root -> lewy);
    wypisz (root -> prawy);
}

int main (){
    struct heap_el *korzen = 0;
    wstaw(&korzen, 4);
    wstaw(&korzen, 2);
    wstaw(&korzen, 6);
    wstaw(&korzen, 1);
    wstaw(&korzen, 3);
    wstaw(&korzen, 5);
    wstaw(&korzen, 7);
    wypisz (korzen);
    return 0;
}