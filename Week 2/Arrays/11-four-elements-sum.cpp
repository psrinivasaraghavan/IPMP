#include <bits/stdc++.h>
using namespace std;


void findFourElements(int a[], int n, int sum)
{
    sort(a, a + n);
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                int csum = a[i] + a[j] + a[l] + a[r];
                if (csum == sum)
                {
                    cout << a[i] << " " << a[j] << " " << a[l] << " " << a[r] << endl;
                    return;
                }
                else if (csum < sum)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
    }
    cout << "No such four elements can be found in this array." << endl;
}


int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9},  n = sizeof(a) / sizeof(a[0]), sum = 21;
    findFourElements(a, n, sum);
    return 0;
}
