#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ncurses.h> //to work properly need to download this library
#define SIZE 9
#define SUMA_W_WIERSZU 45
#define SMALL_SIZE 3

    int sudoku_puste1[SIZE][SIZE]={  {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},

                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},

                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},
    };
    int sudoku_puste2[SIZE][SIZE]={  {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},

                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},

                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},
                                     {0,0,0, 0,0,0, 0,0,0},
    };
void print_sudoku(int sudoku[SIZE][SIZE])
{
    int i, j;
    printf ("\n");
    for (i=0; i<SIZE; ++i)
        {
        for (j=0; j<SIZE; ++j)
        {
            printf("%d ", sudoku[i][j]);
            if (j%SMALL_SIZE==2) printf (" ");
        }
        printf ("\n");
        if (i%SMALL_SIZE==2)
        printf ("\n");
        }
    printf ("\n");

}
void printw_sudoku(int sudoku[SIZE][SIZE])
{
    int i, j;
    initscr();
    move(0,0);
    for (i=0; i<SIZE; ++i)
        {
        for (j=0; j<SIZE; ++j)
        {
            printw("%d ", sudoku[i][j]);
            if (j%SMALL_SIZE==2) printw (" ");
        }
        printw ("\n");
        if (i%SMALL_SIZE==2)
        printw ("\n");
        }
    getch();
    endwin();
}
bool does_it_suit(int tab[SIZE][SIZE], int a, int b, int tested) /*należy pamiętać że a i b powinny pomniejszone o 1 ponieważ jezyk C inaczej numeruje pozycje tablicy niż ludzie (0=1) (1=2)...*/
{
    if (tested<1||tested>9) return (false);
    int i, j;
    for (i=0; i<SIZE; ++i) /*checking rows*/
        {
            if(tab[a][i]==tested)
            return (false);
        }
    for (i=0; i<SIZE; ++i)
        {
            if (tab[i][b]==tested) /*checking columns*/
            return (false);
        }
    for (i=a-a%SMALL_SIZE; i<SMALL_SIZE*(a/SMALL_SIZE+1); ++i) /*checking smallsquares*/
        {
        for (j=b-b%SMALL_SIZE; j<SMALL_SIZE*(b/SMALL_SIZE+1); ++j)
        {
            if (tab[i][j]==tested)
            return (false);
        }
        }
    return (true);
}

bool check_if_correctv2(int sudoku[SIZE][SIZE])
{
    int i,j, suma=0;
    for (i=0; i<SIZE; ++i)
    {
        for (j=0,suma=0; j<SIZE; ++j)
        {
            suma+=sudoku[i][j];
        }
        if (suma!=SUMA_W_WIERSZU)
        {
            printf("blad w wierszu: %d.\n", i+1);
            return (false);

        }
    }
    for (j=0, suma=0; j<SIZE; ++j)
    {
        for (i=0, suma=0; i<SIZE; ++i)
        {
            suma+=sudoku[i][j];
        }
        if (suma!=SUMA_W_WIERSZU)
        {
            printf("blad w kolumnie: %d.\n", j+1);
            return (false);
        }
    }
    return true;
}
void make_it_easier (int sudoku[SIZE][SIZE])
{
    int licznik, i, j, k, save_k, keepgoing=0;
    for (i=0; i<SIZE; ++i)
    {
        for (j=0; j<SIZE; ++j)
        {
            if (!sudoku[i][j])
            {
                for (k=1, licznik=0; k<=SIZE; ++k)
                {
                if (does_it_suit(sudoku, i, j, k))
                    {
                    licznik++;
                    save_k=k;
                    }
                }
            }
            if (licznik==1)
                {
                    sudoku[i][j]=save_k;
                    /*print_sudoku(sudoku);
                    sleep(1);
                    fflush(stdout);*/
                    keepgoing=1;
                    licznik=0;
                }
        }
    }
    if (keepgoing) make_it_easier(sudoku);
}

bool solverv2(int sudoku[SIZE][SIZE], int w, int k)
{
    if (w==SIZE) return (true);
    int i;
    if (k==SIZE)
    {
        return solverv2(sudoku, w+1, 0);
    }
    if (sudoku[w][k]>0)
    {
        return solverv2(sudoku, w, k+1);
    }
    for (i=1; i<=SIZE; ++i)
    {
        //printw_sudoku(sudoku);
        if (does_it_suit(sudoku, w, k, i))
        {
            sudoku[w][k]=i;
            if (solverv2(sudoku, w, k+1))
                return (true);
        }
        sudoku[w][k]=0;

    }
    return (false);
}
bool solver(int sudoku[SIZE][SIZE], int w, int k)
{
    if (w==SIZE) return (true);
    int i;
    if (k==SIZE)
    {
        return solver(sudoku, w+1, 0);
    }
    if (sudoku[w][k]>0)
    {
        return solver(sudoku, w, k+1);
    }
    for (i=1; i<=SIZE; ++i)
    {
        printw_sudoku(sudoku);
        if (does_it_suit(sudoku, w, k, i))
        {
            sudoku[w][k]=i;
            if (solver(sudoku, w, k+1))
                return (true);
        }
        sudoku[w][k]=0;

    }
    return (false);
}
int main ()
{

    FILE * fp;
    int x;
    clock_t start1, stop1, start2, stop2;
    char odp;
    printf ("co chcesz zrobic?\n1- rozwiazanie sudoku dowolnej trudnosci\n2- porownanie dzialania czasu rozwiazywania sudoku przez algorytmy\n3- zaobserwowac dzialanie algorytumu z backtrackingiem\n     UWAGA: uzywaj dowolnego kwaisza do poakzywanai kolejnego kroku");
    printf ("\n4- rozwiazac latwe sudoku algorytmem szybszym, ale nie radzacym sobie z trudniejszymi sudoku\n\n");
    scanf ("%d", &x);
    switch (x)
    {
        case 1:
        {
        fp=fopen ("/home/student/Pulpit/programowanie/sudoku.txt", "r");
        if (fp==NULL)
        {
            printf("blad odczytu pliku");
            exit(1);
        }
        for (int i=0; i<SIZE; ++i)
        {
            for (int j=0; j<SIZE; ++j)
            {
                fscanf(fp, "%d", &sudoku_puste1[i][j]);
            }
        }
        printf("rozwiazywane sudoku");
        print_sudoku(sudoku_puste1);
        if (solverv2(sudoku_puste1, 0, 0))
        {
        print_sudoku(sudoku_puste1);
        printf ("chcesz sprawdzic czy podane sudoku jest na pewno dobrze rozwiazane?(t/n)\n");
        scanf ("%s", &odp);
        if (odp =='t')
        if(check_if_correctv2(sudoku_puste1)) printf("jasne ze jest :D\n");
        }
        else
        printf("nie da sie rozwiazac\n");
        break;
        }
        case 2:
        {
        fp=fopen ("/home/student/Pulpit/programowanie/sudoku_latwe.txt", "r");
        if (fp==NULL)
        {
            printf("blad odczytu pliku");
            exit(1);
        }
        for (int i=0; i<SIZE; ++i)
        {
            for (int j=0; j<SIZE; ++j)
            {
                fscanf(fp, "%d", &sudoku_puste1[i][j]);
                fscanf(fp, "%d", &sudoku_puste2[i][j]);
            }
        }
        printf("rozwiazywane sudoku");
        print_sudoku(sudoku_puste1);
        start1=clock();
        make_it_easier(sudoku_puste1);
        stop1 = clock();
        start2=clock();
        solverv2(sudoku_puste2, 0, 0);
        stop2 = clock();
        print_sudoku(sudoku_puste1);
        float sec1= (float)(stop1-start1)/CLOCKS_PER_SEC;
        float sec2= (float)(stop2-start2)/CLOCKS_PER_SEC;
        printf("czas dzialania make_it_easier: %lf\n", sec1);
        printf("czas dzialania solverv2: %lf\n", sec2);
        break;
        }
        
        case 3:
        {
        fp=fopen ("/home/student/Pulpit/programowanie/sudoku_latwe.txt", "r");
        if (fp==NULL)
        {
            printf("blad odczytu pliku");
            exit(1);
        }
        for (int i=0; i<SIZE; ++i)
        {
            for (int j=0; j<SIZE; ++j)
            {
                fscanf(fp, "%d", &sudoku_puste1[i][j]);
            }
        }
        if (solver(sudoku_puste1, 0, 0))
        {
            printf ("KONIEC, sudoku rozwiazane");
            print_sudoku(sudoku_puste1);
        }
        else
        printf("nie da sie rozwiazac\n");
        break;
        }
        
        case 4:
        {
        fp=fopen ("/home/student/Pulpit/programowanie/sudoku_latwe.txt", "r");
        if (fp==NULL)
        {
            printf("blad odczytu pliku");
            exit(1);
        }
        for (int i=0; i<SIZE; ++i)
        {
            for (int j=0; j<SIZE; ++j)
            {
                fscanf(fp, "%d", &sudoku_puste1[i][j]);
            }
        }
        printf("rozwiazywane sudoku");
        print_sudoku(sudoku_puste1);
        make_it_easier(sudoku_puste1);
        print_sudoku(sudoku_puste1);
        break;
        }
        
        default:
        printf ("nie ma przypisanego dzialania do liczby %d", x);
        break;
    }
    fclose(fp);
    return 0;
}