#include <iostream>
using namespace std;

 
void segregate(int a[], int n)
{
    int l = 0, r = n-1;
    while (l < r)
    {
        while (a[l] % 2 == 0 && l < r) l++;
        while (a[r] % 2 == 1 && l < r) r--;
        if (l < r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
}
 

int main()
{
    int a[] = {12, 34, 45, 9, 8, 90, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int i = 0;
    segregate(a, n);
    cout <<"The array after segregation ";
    for (i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}