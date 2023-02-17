#include <bits/stdc++.h>
using namespace std;
 

char* removeUtil(char* s, char* lastRemoved)
{
    if (s[0] == '\0' || s[1] == '\0') return s;
    if (s[0] == s[1]) 
    {
        *lastRemoved = s[0];
        while (s[1] && s[0] == s[1]) s++;
        s++;
        return removeUtil(s, lastRemoved);
    }
    char* rem_str = removeUtil(s + 1, lastRemoved);
    if (rem_str[0] && rem_str[0] == s[0])
    {
        *lastRemoved = s[0];
        return (rem_str + 1);
    }
    if (rem_str[0] == '\0' && *lastRemoved == s[0]) return rem_str;
    rem_str--;
    rem_str[0] = s[0];
    return rem_str;
}
 

char* removedp(char* s)
{
    char lastRemoved = '\0';
    return removeUtil(s, &lastRemoved);
}
 

int main()
{
    char s1[] = "hoteeellll"; cout << removedp(s1) << endl;
    char s2[] = "azxxxzy"; cout << removedp(s2) << endl;
    char s3[] = "caaabbdbaac"; cout << removedp(s3) << endl;
    return 0;
}