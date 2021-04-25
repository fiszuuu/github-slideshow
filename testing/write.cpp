#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
 
int main ()
{
    const char* a = "cipaaa";
    for (int i = 0; i<strlen(a); i++) cout.write(a, i);
    return 0;
}