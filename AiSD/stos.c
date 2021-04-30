#include <stdio.h>
#include <time.h>
#include <stdlib.h>



double stos[100]; 

int szczyt=0; 

 

void wstaw(double w){ 
    if (szczyt > 99)
    {
        printf("ERROR");
        return;
    }
    stos[szczyt++]=w; 
} 

 

double pobierz(void){ 
    if (szczyt <= 0)
    {
        printf("ERROR");
        return;
    }
    return stos[--szczyt]; 
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