#include <iostream>
using namespace std;
 

void majorityElement(int a[], int n)
{
    int maxCount = 0, index = -1; 
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++) if (a[i] == a[j]) c++;
        if (c > maxCount) {
            maxCount = c;
            index = i;
        }
    }
    if (maxCount > n / 2) cout << a[index] << endl;
    else cout << "There is no majority element." << endl;
}
 

int main()
{
    int a[] = { 45, 45, 20, 45, 43, 50, 45 };
    int n = sizeof(a) / sizeof(a[0]);
    majorityElement(a, n);
    return 0;
}