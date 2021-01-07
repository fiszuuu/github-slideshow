#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define BOARDSIZE 3
#define LOST -1
#define WON  1
#define DRAW 0
#define MOVES 9
char board[BOARDSIZE][BOARDSIZE]={      ' ',' ',' ',
                                        ' ',' ',' ',
                                        ' ',' ',' '
    };
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

bool yourmove (char board[BOARDSIZE][BOARDSIZE], int x, int y)
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
int computermoves (int board[BOARDSIZE][BOARDSIZE], int x)
{
    if (!wincheck(board)) return DRAW;
    
    
}
int main ()
{
    srand(time(NULL));
    int a=rand()%4;
    printf("POKONAJ MNIE!\ngrasz jako X");
    switch (a)
    {
    case 0:
        board[0][0]='O';
        break;
    case 1:
        board[0][2]='O';
        break;
    case 2:
        board[2][0]='O';
        break;
    case 3:
        board[2][2]='O';
        break;    
    default: printf("jakis blad");
        break;
    }
    printboard(board);
    int x, y;
    for (int i=1; i<MOVES; ++i)
    {
        scanf("%d%d", &x, &y);
        yourmove(board, x, y);
        printboard(board);
    }
    
    return 0;
}