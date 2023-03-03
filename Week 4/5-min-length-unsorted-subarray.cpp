#include<bits/stdc++.h>
using namespace std;


void printUnsorted(int a[], int n)
{
    int s = 0, e = n-1, i, max, min;
    for (s = 0; s < n-1; s++) if (a[s] > a[s+1]) break;
    if (s == n-1)
    {
        cout << "The complete array is sorted";
        return;
    }
    for(e = n - 1; e > 0; e--) if(a[e] < a[e-1]) break;
    max = a[s]; min = a[s];
    for(i = s + 1; i <= e; i++)
    {
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    for( i = 0; i < s; i++)
    {
        if(a[i] > min)
        {
            s = i;
            break;
        }	
    }
    for( i = n -1; i >= e+1; i--)
    {
        if(a[i] < max)
        {
            e = i;
            break;
        }
    }
    cout << "The unsorted subarray which" << " makes the given array" << endl << "sorted lies between the indices " << s << " and " << e;
    return;
}


int main()
{
	int a[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int n = sizeof(a)/sizeof(a[0]);
	printUnsorted(a, n);
	getchar();
	return 0;
}
