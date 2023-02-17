#include <iostream>
#include <algorithm>
using namespace std;
bool find_three_nums(int a[], int n, int sum)
{
    int l, r;
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++) {
        l = i + 1; 
        r = n - 1;
        while (l < r) {
            if (a[i] + a[l] + a[r] == sum) {
                printf("Triplet is %d, %d, %d.\n", a[i], a[l],a[r]);
                return true;
            }
            else if (a[i] + a[l] + a[r] < sum) l++;
            else r--;
        }
    }
    return false;
}
 

int main()
{
    int a[] = { 11, 4, 15, 16, 13, 28 };
    int sum = 42;
    int n = sizeof(a) / sizeof(a[0]);
    find_three_nums(a, n, sum);
    return 0;
}