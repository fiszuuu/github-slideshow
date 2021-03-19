#include <stdio.h>
#include <stdbool.h>
#define BOARDSIZE 3
#define LOST -1
#define WON  1
#define DRAW 0
#define MOVES 9
char board[BOARDSIZE][BOARDSIZE]={ "   ","   ","   ",};
void printboard (char board[BOARDSIZE][BOARDSIZE])
{
    int i, j;
    printf("\n  1 2 3");
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
int wincheck (char board[BOARDSIZE][BOARDSIZE])
{
    if ((board[0][0]=='X' && board[0][1]=='X' && board [0][2]=='X') ||
        (board[0][0]=='X' && board[1][0]=='X' && board [2][0]=='X') ||
        (board[0][0]=='X' && board[1][1]=='X' && board [2][2]=='X') ||
        (board[1][0]=='X' && board[1][1]=='X' && board [1][2]=='X') ||
        (board[2][0]=='X' && board[2][1]=='X' && board [2][2]=='X') ||
        (board[0][1]=='X' && board[1][1]=='X' && board [2][1]=='X') ||
        (board[0][0]=='X' && board[1][1]=='X' && board [2][2]=='X')
    )
    return LOST;
    if ((board[0][0]=='O' && board[0][1]=='O' && board [0][2]=='O') ||
        (board[0][0]=='O' && board[1][0]=='O' && board [2][0]=='O') ||
        (board[0][0]=='O' && board[1][1]=='O' && board [2][2]=='O') ||
        (board[1][0]=='O' && board[1][1]=='O' && board [1][2]=='O') ||
        (board[2][0]=='O' && board[2][1]=='O' && board [2][2]=='O') ||
        (board[0][1]=='O' && board[1][1]=='O' && board [2][1]=='O') ||
        (board[0][0]=='O' && board[1][1]=='O' && board [2][2]=='O')
    )
    return WON;
    else
    return DRAW;
}
bool isfree (char board[BOARDSIZE][BOARDSIZE], int x, int y)
{
    if (board[x][y]==' ') return true;
    return false;
}

bool Xmoves (char board[BOARDSIZE][BOARDSIZE], int x, int y)
{
    if (x>0 && x<=BOARDSIZE && y>0 && y<=BOARDSIZE )
    {
        if (isfree(board, x-1, y-1))
        {
            board[x-1][y-1]='X';
            return true;
        }
        else 
        printf ("pole zajete\n");
    }
    else 
    {
        printf("blednie podane wspolrzedne\n");
        return false;
    }
}
bool Omoves (char board[BOARDSIZE][BOARDSIZE], int x, int y)
{
    if (x>0 && x<=BOARDSIZE && y>0 && y<=BOARDSIZE)
    {
        if (isfree(board, x-1, y-1))
        {
            board[x-1][y-1]='O';
            return true;
        }
        else 
        printf ("pole zajete");
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
    printboard(board);
    while (!wincheck(board))
    {
        if (whosmove==1)
        {
            printf("gracz O, ");
            printf("Podaj wspolrzedne (najpierw wiersz, potem kolumna)\n");
            scanf("%d%d", &x, &y);
            Omoves(board, x, y );
        }
        else
        {
            printf("gracz X, ");
            printf("Podaj wspolrzedne (najpierw wiersz, potem kolumna)\n");
            scanf("%d%d", &x, &y);
            Xmoves(board, x, y );
        }
        printboard(board);
        if (wincheck(board)==LOST) 
        {
            printf ("wygrywa gracz X\n");
            return 0;
        }
        if (wincheck(board)==WON)  
        {
            printf ("wygrywa gracz O\n");
            return 0;
        }
        whosmove*=-1;
    } 
    printf ("REMIS");
    return 0;
}