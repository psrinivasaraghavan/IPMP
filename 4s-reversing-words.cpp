#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string s[] = {"Hello", "Welcome", "to", "this", "world"}, ans = "";
    for (int i = 4; i >= 0; i--) ans += s[i] + " ";
    
    cout << (ans.substr(0, ans.length() - 1)) << endl;
    return 0;
}