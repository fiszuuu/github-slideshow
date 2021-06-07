#include <stdio.h>


struct krawedz{ 
    int u; 
    int v; 
    double waga; 
}; 


double kolejka[100]; 

int poczatek = 0, koniec = 0, liczba_ele = 0, dlugosc = 100; 
 

void wstaw(double a){ 
    if(liczba_ele == dlugosc) return; 
    kolejka[koniec++] = a; 
    liczba_ele++; 
    if(koniec == dlugosc) koniec = 0; 
} 

double pobierz(void){ 
    if(liczba_ele == 0) return -1; 
    liczba_ele--; 
    double helper = kolejka[poczatek++]; 
    if(poczatek == dlugosc) poczatek = 0; 
    return helper; 
} 

void bfs(struct krawedz *krawedzie, int s, int n, int m, int *poprzednik, int *d){ 
    int odwiedzone[n]; 
    int u; 
         for (int i=0; i<n; i++){ 
                 poprzednik[i] = -1; 
                 odwiedzone[i] = 0; 
            } 
         odwiedzone[s]=1; 
         wstaw(s); 
         while(liczba_ele>0){ 
            u = pobierz(); 
            for (int i=0; i<m; i++){ 
                if (krawedzie[i].u==u){ 
                     if(odwiedzone[krawedzie[i].v]==0){ 
                            d[krawedzie[i].v] = d[u]+1; 
                            odwiedzone[krawedzie[i].v]=1; 
                            poprzednik[krawedzie[i].v]=u; 
                            wstaw(krawedzie[i].v); 
                        } 
                  }
            }
         }
} 

void dfs(struct krawedz *krawedzie, int u, int n, int m, int *poprzednik, int *odwiedzone){ 
    odwiedzone[u] = 1; 
    for (int i=0; i<m; i++){ 
        if(krawedzie[i].u == u){ 
            if(odwiedzone[krawedzie[i].v] == 0){ 
            poprzednik[krawedzie[i].v] = u; 
            dfs(krawedzie, krawedzie[i].v, n, m, poprzednik, odwiedzone); 
            } 
        }
    } 
}

int main(){ 
    struct krawedz krawedzie[6] = {{0,1,1},{0,4,1},{0,3,2},{1,2,2},{3,2,2},{4,3,5}}; 
    int n = 5; 
    int m = 6; 
    int prev[n]; 
    int d[n];
    bfs(krawedzie,0,n,m,prev,d); 
    for(int i=0;i<n;i++){ 
        printf("Numer wierzchołka= %d poprzednik = %d d = %d\n",i,prev[i],d[i]); 
    } 
    return 0; 
} 