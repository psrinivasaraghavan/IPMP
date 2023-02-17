#include <iostream>
using namespace std;
  

int main()
{
    int a[] = { 0, 1, 0, 1, 1, 1 };
    int n = sizeof(a) / sizeof(a[0]), count = 0;
    for (int i = 0; i < n; i++) if (a[i] == 0) count++;
    for (int i = 0; i < count; i++) a[i] = 0;
    for (int i = count; i < n; i++) a[i] = 1;
    cout << "Array after segregation is ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}