#include<iostream>
using namespace std;
 

void elementsGreaterThanRightElements(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++) if (a[i] <= a[j]) break;
        if (j == n) cout << a[i] << " ";
    }
}
 

int main()
{
    int a[] = {17, 16, 5, 2, 14, 11}, n = sizeof(a)/sizeof(a[0]);
    elementsGreaterThanRightElements(a, n);
    return 0;
}