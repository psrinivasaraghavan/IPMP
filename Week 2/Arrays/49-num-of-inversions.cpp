#include <iostream>
using namespace std;
  

int merge(int a[], int t[], int l, int m, int r)
{
    int i, j, k, inv_count = 0;
    i = l;
    j = m;
    k = l;
    while (i <= m - 1 && j <= r) {
        if (a[i] <= a[j]) t[k++] = a[i++];
        else {
            t[k++] = a[j++];
            inv_count += (m - i);
        }
    }
    while (i <= m - 1) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = t[i];
    return inv_count;
}
  
int _mergeSort(int a[], int t[], int l, int r)
{
    int m, inv_count = 0;
    if (r > l) {
        m = (r + l) / 2;
        inv_count += _mergeSort(a, t, l, m);
        inv_count += _mergeSort(a, t, m + 1, r);
        inv_count += merge(a, t, l, m + 1, r);
    }
    return inv_count;
}


int main()
{
    int a[] = { 2, 10, 7, 3, 5 }, n = sizeof(a) / sizeof(a[0]), t[n];
    int ans = _mergeSort(a, t, 0, n - 1);
    cout << "The number of inversions are " << ans << "." <<endl;
    return 0;
}
  