#include <iostream>
using namespace std;
 

bool checkPair(int a[], int size, int x)
{
    for (int i = 0; i < (size - 1); i++) {
        for (int j = (i + 1); j < size; j++) {
            if (a[i] + a[j] == x) {
                return 1;
            }
        }
    }
 
    return 0;
}
 

int main()
{
    int a[] = {0, -1, 2, -3, 1};
    int x = -2;
    int size = sizeof(a) / sizeof(a[0]);
    if (checkPair(a, size, x)) cout << "Yes" << endl;
    else cout << "No" << x << endl;
    return 0;
}