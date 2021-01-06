#include <stdio.h>
#include <stdbool.h>
#define BOARDSIZE 3
#define LOST -1
#define WON  1
#define DRAW 0
void printboard (char board[BOARDSIZE][BOARDSIZE])
{
    int i, j;
    for (i=0; i<BOARDSIZE; ++i)
        {
            for (j=0; j<BOARDSIZE; ++j)
            {
                    /*if (board[i][j]=='O') printf("O");
                    if (board[i][j]=='X') printf("X");
                    if (board[i][j]==' ') printf("-");*/
                    printf ("%c", board[i][j]);
                    printf(" ");
            }
            printf("\n");
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

int main ()
{
    char board[BOARDSIZE][BOARDSIZE]={  'X','X','X',
                                        'O',' ',' ',
                                        ' ','X',' '
    };
    /*printboard(board);
    if (wincheck(board)==LOST)
    printf ("wygraywa O\n");
    for (int i=0; i<BOARDSIZE; ++i)
        {
            for (int j=0; j<BOARDSIZE; ++j)
            {
                if(isfree(board, i, j)) printf ("miejsce o wpolrzednych %d %d jest wolne\n", i+1, j+1);
            }
        }*/
    
    return 0;
}