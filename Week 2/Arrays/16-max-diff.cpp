#include <iostream>
using namespace std;
  

int md(int a[], int n)
{
    int md = -1, maxRight = a[n-1]; 
    for (int i = n-2; i >= 0; i--)
    {
        if (a[i] > maxRight) maxRight = a[i];
        else
        {
            int diff = maxRight - a[i];
            if (diff > md) md = diff;
        }
    }
    return md;
}
  

int main()
{
  int a[] = {1, 2, 90, 10, 100};
  int n = sizeof(a) / sizeof(a[0]);
  cout << "Maximum difference is " << md(a, n) << endl;
  return 0;
}