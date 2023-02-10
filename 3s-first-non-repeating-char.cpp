
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string string = "Hello";
    int i = -1;
    char fnc = ' ';
    for (auto i : string) {
        if (count(string.begin(), string.end(), i) == 1) {
            fnc = i;
            break;
        }
        else i += 1;
    }
    if (i == 1) cout << "Either all characters are repeating or ""string is empty"<< endl;
    else cout << "First non-repeating character is " << fnc<< endl;
    return 0;
}
