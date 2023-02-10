#include <bits/stdc++.h>
using namespace std;
 

void reverse(char *a, int n, int i)
{
    if(i == n) return;

    char temp = a[i];   
    reverse(a, n, i+1);  
    cout << temp;              
}
 

int main()
{
    char a[] = "Hello World!";
    int n = sizeof(a) / sizeof(a[0]);
    reverse(a, n, 0);
    return 0;
}