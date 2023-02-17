#include <bits/stdc++.h>
using namespace std;
  
int maxSubArraySum(int a[], int n)
{
    int maxfound = INT_MIN, newMax = 0;
    for (int i = 0; i < n; i++) {
        newMax += a[i];
        if (maxfound < newMax) maxfound = newMax;
        if (newMax < 0) newMax = 0;
    }
    return maxfound;
}
  

int main()
{
    int a[] = { -2, 3, 4, -1, -2, 1, 5, -1 }, n = sizeof(a) / sizeof(a[0]);
    cout << "The maximum contiguous sum is " << maxSubArraySum(a, n);
    return 0;
}