#include <bits/stdc++.h>
using namespace std;
#define NA -1


void moveToEnd(int mPlusN[], int n)
{
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--) if (mPlusN[i] != NA) mPlusN[j--] = mPlusN[i];
}


void merge(int mPlusN[], int N[], int m, int n)
{
    int i = n, j = 0, k = 0; 
    while (k < (m + n))
    {
        if ((j == n) || (i < (m + n) && mPlusN[i] <= N[j])) mPlusN[k++] = mPlusN[i++];
        else mPlusN[k++] = N[j++];
    }
}


void print(int a[], int n)
{
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}


int main()
{
    int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20}, N[] = {5, 7, 9, 25};
    int n = sizeof(N) / sizeof(N[0]), m = sizeof(mPlusN) / sizeof(mPlusN[0]) - n;
    moveToEnd(mPlusN, m + n);
    merge(mPlusN, N, m, n);
    print(mPlusN, m+n);
    return 0;
}
