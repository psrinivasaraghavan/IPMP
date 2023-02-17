#include <bits/stdc++.h>
using namespace std;
 

void pa(int a[], int n)
{
    if (n == 1) {
        cout << 0;
        return;
    }
    int i, t = 1;
    int* p = new int[(sizeof(int) * n)];
    memset(p, 1, n);
    for (i = 0; i < n; i++) {
        p[i] = t;
        t *= a[i];
    }
    t = 1;
    for (i = n - 1; i >= 0; i--) {
        p[i] *= t;
        t *= a[i];
    }
    for (i = 0; i < n; i++) cout << p[i] << " ";
}
 

int main()
{
    int a[] = { 1, 4, 5, 8, 2 }, n = sizeof(a) / sizeof(a[0]);
    cout << "The product array is: \n";
    pa(a, n);
}