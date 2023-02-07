#include<iostream>
using namespace std;
int odd_occurrence(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }
        if (count % 2 != 0) return a[i];
    }
    return -1;
}
 

int main()
{
    int a[] = {12, 3, 5, 4, 5, 13, 2, 4, 3, 5, 4, 4, 2, 13, 12};
    int n = sizeof(a) / sizeof(a[0]);
    cout << odd_occurrence(a, n)<<endl;
    return 0;
}