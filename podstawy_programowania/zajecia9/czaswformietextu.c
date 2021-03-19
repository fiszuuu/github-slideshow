#include <stdio.h>
#include <time.h>


int main ()
{
    time_t sek;
    struct tm *wsk_strukt;
    char napis[50];
    time (&sek);
    wsk_strukt = localtime (&sek);
    strftime (napis, 50, "teraz mamy %c", wsk_strukt);
    printf ("%s", napis);
    return 0;
}
