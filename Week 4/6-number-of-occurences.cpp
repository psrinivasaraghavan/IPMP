#include <bits/stdc++.h>
using namespace std;


int count(int a[], int x, int n)
{	
    int *l = lower_bound(a, a+n, x);
    if (l == (a + n) || *l != x) return 0;
    int *r = upper_bound(l, a+n, x);	
    return r - l;
}


int main()
{
    int a[] = {1, 2, 2, 3, 3, 3, 3},  x = 3, n = sizeof(a)/sizeof(a[0]), c = count(a, x, n);
    cout << x << " occurs " << c << " times.";
    return 0;
}
