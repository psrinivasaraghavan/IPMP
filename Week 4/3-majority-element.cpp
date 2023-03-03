#include<bits/stdc++.h>
using namespace std;

int bsearch(int a[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = (l + r)/2; 
		if ((mid == 0 || x > a[mid - 1]) && (a[mid] == x)) return mid;
		else if (x > a[mid]) return bsearch(a, (mid + 1), r, x);
		else return bsearch(a, l, (mid - 1), x);
	}
	return -1;
}


bool isMajority(int a[], int n, int x)
{
	int i = bsearch(a, 0, n - 1, x);
	if (i == -1) return false;
	if (((i + n / 2) <= (n - 1)) && a[i + n / 2] == x) return true;
	else return false;
}


int main()
{
	int a[] = {1, 3, 4, 4, 4, 4, 7}, n = sizeof(a) / sizeof(a[0]), x = 3;
	if (isMajority(a, n, x)) cout << x << " appears more than " << n / 2 << " times in a[]" << endl;
	else cout << x << " does not appear more than" << n / 2 << " times in a[]" << endl;
	return 0;
}
