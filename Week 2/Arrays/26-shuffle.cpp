#include <bits/stdc++.h>
using namespace std;
 
void randomize(int a[], int n)
{
    srand (time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(a[i], a[j]);
    }
}
 
int main()
{
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    randomize(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}