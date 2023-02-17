#include <iostream>
using namespace std;


int main()
{
    int a[] = { 0, 4, 3, 8, 7, 8, 2, 4, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++) {
        a[a[i] % n] = a[a[i] % n] + n;
    }
    cout << "The repeating elements are: " << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] >= n * 2) {
            cout << i << " " << endl;
        }
    }
    return 0;
}
  