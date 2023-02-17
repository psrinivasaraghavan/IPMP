#include <bits/stdc++.h>
using namespace std;


void minDifference(int a[], int n)
{
    sort(a, a + n);
    int md = INT_MAX, n1, n2;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = abs(a[i] - a[i+1]);
        if (diff < md)
        {
            md = diff;
            n1 = a[i];
            n2 = a[i+1];
        }
    }
    cout << "The two numbers with the minimum difference are " << n1 << " and " << n2 << "." << endl;
}


int main()
{
    int a[] = {1, 5, 3, 19, 25, 18}, n = sizeof(a) / sizeof(a[0]);
    minDifference(a, n);
    return 0;
}
