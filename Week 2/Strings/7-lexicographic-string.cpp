#include <bits/stdc++.h>
using namespace std;
 

int fact(int n) {
    return (n <= 1) ? 1 : n * fact(n - 1);
}
 

int findSmallerInRight(string s, int l, int h)
{
    int countRight = 0, i;
    for (i = l + 1; i <= h; ++i) if (s[i] < s[l]) ++countRight;
    return countRight;
}
 

int findrank(string s)
{
    int len = s.size(), mul = fact(len), r = 1, countRight, i;
    for (i = 0; i < len; ++i) {
        mul /= len - i;
        countRight = findSmallerInRight(s, i, len - 1);
        r += countRight * mul;
    }
    return r;
}


int main()
{
    string s = "string";
    cout << findrank(s);
    return 0;
}