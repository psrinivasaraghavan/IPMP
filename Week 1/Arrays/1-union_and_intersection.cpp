#include <iostream>
using namespace std;
void Union(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) cout << a[i++] << " ";
        else if (b[j] < a[i]) cout << b[j++] << " ";
        else {
            cout << b[j++] << " ";
            i++;
        }
    }
 
    while (i < m) cout << a[i++] << " ";
    while (j < n) cout << b[j++] << " ";
}
 

void intersection(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (j < n && i < m) {
        if (a[i] < b[j]) i++;
        else if (b[j] < a[i]) j++;
        else
        {
            cout << b[j] << " ";
            i++;
            j++;
        }
    }
}
 
    

int main()
{
    int a[] = { 1, 2, 4, 6, 7 };
    int b[] = { 1, 3, 4, 7 };
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    cout<<"The union of the two given sets is: ";
    Union(a, b, m, n);
    cout<<endl<<"The intersection of the two given sets is: ";
    intersection(a, b, m, n);
    return 0;
}