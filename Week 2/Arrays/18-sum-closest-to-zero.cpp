#include <bits/stdc++.h>
using namespace std;
 

bool cmp(int x, int y)
{
    return abs(x) < abs(y);
}
 
void findMinSum(int a[], int n)
{
    sort(a, a + n, cmp);
    int min = INT_MAX, x, y;
    for (int i = 1; i < n; i++) {
        if (abs(a[i - 1] + a[i]) <= min) {
            min = abs(a[i - 1] + a[i]);
            x = i - 1;
            y = i;
        }
    }
    cout << "The two elements whose sum is minimum are " << a[x] << " and " << a[y];
}
 

int main()
{
    int a[] = { 1, 60, -10, 70, -60, 85 };
    int n = sizeof(a) / sizeof(a[0]);
    findMinSum(a, n);
    return 0;
}