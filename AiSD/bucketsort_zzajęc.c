#include <stdio.h>


struct el_listy{ 
    int next; 
    int value; 
}; 


int sort(int *tab, int n, int liczba_kubelkow, struct  el_listy *element){ 
    int poczatek[liczba_kubelkow+1]; 
    int koniec[liczba_kubelkow+1]; 
    struct el_listy *ws=element; 
    int ws0, ws2; 
    for(int i=0;i<liczba_kubelkow+1;i++){ 
        poczatek[i]=-1; 
        koniec[i]=-1; 
    } 
    for(int i =0;i<n;i++){ 
        ws->value = tab[i]; 
        ws->next=-1; 
        if(poczatek[ws->value]== -1){ 
            poczatek[ws->value] = i; 
            koniec[ws->value]=i; 
        }else{ 
            element[koniec[ws->value]].next=i; 
            koniec[ws->value]=i; 
        } 
        ws++;
        int j;
        for(j =0;poczatek[j]==-1;j++); 
        ws0 = poczatek[j]; 
        ws2 = koniec[j]; 
        for (int k = 0; k < 69; ++k)
            printf("%d ", poczatek[k]);
        printf("\n");
        //printf("%d %d", ws0, ws2);
        for(j++;j<=liczba_kubelkow;j++){ 
            if(poczatek[j]!=-1){ 
                element[ws2].next=poczatek[j]; 
                ws2 = koniec[j]; 
            } 
        } 

    } 
    
    return ws0; 
} 

 

 

int main(){ 
    int tab[10] = {1, 2, 42, 5, 34, 68, 42, 12, 23, 5}; 
    int n =10; 
    int w; 
    int liczba_kubelkow = 68; 
    struct el_listy tab2[10] ; 
    w= sort(tab, n, liczba_kubelkow, tab2); 
    for(int i =0 ; i<n;i++){ 
        printf("%d ",  tab2[w].value); 
        w = tab2[w].next; 
    }
} 