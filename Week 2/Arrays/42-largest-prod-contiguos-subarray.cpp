#include <bits/stdc++.h>
using namespace std;
  

int maxSubArrayProduct(int a[], int n)
{
    int maxPosProd = a[0], minNegProd = a[0], ovMax = a[0];
    for (int i = 1; i < n; i++) {
        int temp = max({ a[i], a[i] * maxPosProd, a[i] * minNegProd });
        minNegProd = min({ a[i], a[i] * maxPosProd, a[i] * minNegProd });
        maxPosProd = temp;
        ovMax = max(ovMax, maxPosProd);
    }
    return ovMax;
}
  

int main()
{
    int a[] = { 1, -3, 7, 8, 2, -2, 0 }, n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum Sub array product is " << maxSubArrayProduct(a, n);
    return 0;
}