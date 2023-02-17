#include <iostream>
using namespace std;
  

int maxWater(int a[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++) 
    {
        int l = a[i];
        for (int j = 0; j < i; j++) l = max(l, a[j]);
        int r = a[i];
        for (int j = i + 1; j < n; j++) r = max(r, a[j]);
        res += (min(l, r) - a[i]);
    }
    return res;
}
  

int main()
{
    int a[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }, n = sizeof(a) / sizeof(a[0]);
    cout << maxWater(a, n);
    return 0;
}