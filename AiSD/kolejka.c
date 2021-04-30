#include <stdlib.h>
#include <stdio.h>

double kolejka[100];
int poczatek = 0, koniec = 0, liczba_ele=0, dlugosc =100;

bool wstaw(double a){ 
    if(liczba_ele == dlugosc) return false; 
    kolejka[koniec++] = a; 
    liczba_ele++; 
    if(koniec == dlugosc) koniec = 0; 
    return true;
} 

 

double pobierz(void){ 
    if(liczba_ele == 0) return -1; 
    liczba_ele--; 
    double helper = kolejka[poczatek++]; 
    if(poczatek == dlugosc) poczatek = 0; 
    return helper; 
} 

int main(){ 
    wstaw(7); 
    wstaw(5); 
    wstaw(3); 
    printf("%lf\n", pobierz()); 
    printf("%lf\n", pobierz()); 
    wstaw(15); 
    printf("%lf\n", pobierz()); 
    wstaw(1); 
    printf("%lf\n", pobierz()); 
    printf("%lf\n", pobierz()); 
    printf("%lf\n", pobierz()); 
    return 0; 
}
