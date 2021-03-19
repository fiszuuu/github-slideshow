#include <stdio.h>
#include <stdbool.h>
#define BOARDSIZE 10
#define LOST -1
#define WON  1
#define DRAW 0
char board[BOARDSIZE][BOARDSIZE]={  "XXXXX     ","          ","          ","          ","          ","          ","          ","          ","          ","          ",
    };
void printboard (char board[BOARDSIZE][BOARDSIZE])
{
    int i, j;
    printf("\n  1 2 3 4 5 6 7 8 9 10");
    for (i=0; i<BOARDSIZE; ++i)
        {
            printf("\n%d ", i+1);
            for (j=0; j<BOARDSIZE; ++j)
            {
                    printf ("%c", board[i][j]);
                    printf(" ");
            }

        }
    printf("\n");
}
int wincheck (char board[BOARDSIZE][BOARDSIZE], int towin)
{
    if (towin<3) printf("tak sie nie da grac");
    int n=0;
    for (int i=0; i<BOARDSIZE; ++i)
    {
        for (int j=0; j<BOARDSIZE; ++j)
        {
            if (board[i][j]=='X') n++;
            else n=0; 
        }
        if (n==towin) return WON;
        n=0;
    }
    for (int i=0; i<BOARDSIZE; ++i)
    {
        for (int j=0; j<BOARDSIZE; ++j)
        {
            if (board[j][i]=='X') n++;
            else n=0; 
        }
        if (n==towin) return WON;
        n=0;
    }
    for (int j=0; j<BOARDSIZE; ++j)
    {
        for (int i=0; i<BOARDSIZE-j; ++i)
            {
                if (board[i][i+j]=='X') n++;
            }
        if (n==towin) return WON;
        n=0;
    }
    for (int j=1; j<BOARDSIZE; ++j)
    {
        for (int i=0; i<BOARDSIZE-j; ++i)
            {
                if (board[i+j][i]=='X') n++;
            }
        if (n==towin) return WON;
        n=0;
    }

    return DRAW;
}
bool isfree (char board[BOARDSIZE][BOARDSIZE], int x, int y)
{
    if (board[x][y]==' ') return true;
    return false;
}

bool Xmoves (char board[BOARDSIZE][BOARDSIZE], int x, int y)
{
    printf("Podaj wspolrzedne (najpierw wiersz, potem kolumna)");
    if (x>0 && x<=3 && y>0 && y<=3 && isfree(board, x, y))
    {
        board[x-1][y-1]='X';
        return true;
    }
    else 
    {
        printf("blednie podane wspolrzedne");
        return false;
    }
}
bool Omoves (char board[BOARDSIZE][BOARDSIZE], int x, int y)
{
    printf("podaj wspolrzedne (najpierw wiersz, potem kolumna)");
    if (x>0 && x<=BOARDSIZE && y>0 && y<=BOARDSIZE && isfree(board, x, y))
    {
        board[x-1][y-1]='O';
        return true;
    }
    else 
    {
        printf("blednie podane wspolrzedne");
        return false;
    }
}
int main ()
{
    int x, y, whosmove=1, towin=5;
    printf("zaczyna O\n");
    if (wincheck(board, 3)) printf("wygrywa X");
    /*while (!wincheck)
    {
        if (whosmove==1)
        {
            printf("gracz O, ");
            scanf("%d%d", &x, &y);
            Omoves(board, x, y );
        }
        else
        {
            printf("gracz X, ");
            scanf("%d%d", &x, &y);
            Omoves(board, x, y );
        }
        printboard(board);
        if (towin(board)==whosmove) 
        whosmove*=-1;
    }
    */
    return 0;
}