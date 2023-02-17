#include <bits/stdc++.h>
using namespace std;


void sort3nums(int a[], int n)
{
    int lo = 0, hi = n - 1, mid = 0;
    while (mid <= hi) {
        switch (a[mid]) {
        case 0:
            swap(a[lo++], a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}
  

int main()
{
    int a[] = { 1, 0, 1, 0, 2, 2, 1, 0, 0, 0, 2, 0 };
    int n = sizeof(a) / sizeof(a[0]);
    sort3nums(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}