#include <iostream>
using namespace std;
 

int search(int m[4][4], int n, int x)
{
    if (n == 0) return -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == x) {
                cout << "Element found at (" << i << ", "
                     << j << ")\n";
                return 1;
            }
        }  
    }    
    cout << "Element is not found" << endl;
    return 0;
}
 

int main()
{
    int m[4][4] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    search(m, 4, 4);
    return 0;
}