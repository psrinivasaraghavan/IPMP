#include <bits/stdc++.h>
using namespace std;


int partition(int a[], int l, int r)
{
    int pivot = a[r], i = l - 1;
    for (int j = l; j < r; j++) if (a[j] <= pivot) swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}


int ans(int a[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int pos = partition(a, l, r);
        if (pos - l == k - 1) return a[pos];
        if (pos - l > k - 1) return ans(a, l, pos - 1, k);
        return ans(a, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}


int main() {
    int a[] = { 1, 4, 5, 8, 2 }, n = sizeof(a) / sizeof(a[0]), k=3;
    cout << "The " << k << "th smallest element in the array is: " << ans(a, 0, n - 1, k) << endl;
    return 0;
}
