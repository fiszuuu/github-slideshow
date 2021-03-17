#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "elo";
    s += " mordko";
    s.append(" najlepsza");
    int x = s.find('e');
    while (x!=-1)
    {
        cout<<x<<endl;
        s.erase(x, 1);
        x = s.find('e');
    }

    return 0;
}