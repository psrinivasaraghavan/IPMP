#include <iostream>
using namespace std;
 

void rearrange(int a[], int n)
{
    int i = -1;
    for (int j = 0; j < n; j++) if (a[j] < 0) swap(a[++i], a[j]);
    int p = i + 1, neg = 0;
    while (p < n && neg < p && a[neg] < 0)
    {
        swap(a[neg], a[p]);
        p++;
        neg += 2;
    }
}
 

int main()
{
    int a[] = {-1, 2, -4, -10, 5, 6, -7, 8, -9}, n = sizeof(a) / sizeof(a[0]);
    rearrange(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}