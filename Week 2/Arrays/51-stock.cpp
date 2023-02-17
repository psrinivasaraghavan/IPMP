#include <bits/stdc++.h>
using namespace std;
  

void stock(int a[], int n)
{
    if (n == 1) return;
    int i = 0;
    while (i < n - 1) {
        while (i < n - 1 && a[i] >= a[i + 1]) i++;
        if (i == n - 1) break;
        int buy = i++;
        while (i < n && a[i] >= a[i - 1]) i++;
        int sell = i - 1;
        cout << "Buy the stock on day: " << buy << "\n Sell the stock on day: " << sell << endl;
    }
}
  

int main()
{
    int a[] = { 50, 180, 260, 310, 40, 535, 695 }, n = sizeof(a) / sizeof(a[0]);
    stock(a, n);
    return 0;
}