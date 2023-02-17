#include <iostream>
using namespace std;
 

int myAtoi(char* s)
{
    int r = 0;
    for (int i = 0; s[i] != '\0'; i++) r = r * 10 + s[i] - '0';
    return r;
}
 

int main()
{
    char s[] = "89789";
    int val = myAtoi(s);
    cout << val;
    return 0;
}