#include <iostream>
using namespace std;
  
void rep(int a[], int n)
{
    int i, j;
    cout << "Repeating elements are ";
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                cout << a[i] << " ";
                break;
            }
        }
    }
}
  

int main()
{
    int a[] = { 5, 2, 6, 5, 3, 1, 1, 9, 8 };
    int n = sizeof(a) / sizeof(a[0]);
    rep(a, n);
    return 0;
}