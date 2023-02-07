#include <iostream>
using namespace std; 
int main()
{
    int a[] = { 1, 3, 7, 5, 6, 2 };
    int n = sizeof(a) / sizeof(a[0]);
    int i, temp[n + 1], res;
    for(int i = 0; i <= n; i++) temp[i] = 0;
    for(i = 0; i < n; i++) temp[a[i] - 1] = 1;
    for (i = 0; i <= n ; i++) {
        if (temp[i] == 0) res = i  + 1;
    }
    cout << res;
}