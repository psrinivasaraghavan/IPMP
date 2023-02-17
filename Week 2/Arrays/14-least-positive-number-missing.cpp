#include <iostream>
using namespace std;
 

int missing(int A[], int n)
{
    bool present[n + 1] = { false };
    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n)
            present[A[i]] = true;
    }
    for (int i = 1; i <= n; i++) if (!present[i]) return i;
    return n + 1;
}
 

int main()
{
 
    int a[] = { 0, 3, 1, -1, -7 };
    int size = sizeof(a) / sizeof(a[0]);
    cout << missing(a, size);
}