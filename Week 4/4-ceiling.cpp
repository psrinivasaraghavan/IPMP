#include <bits/stdc++.h>
using namespace std;


int ceilSearch(int a[], int l, int r, int x)
{
	int mid;
	if (x <= a[l]) return l;
	if (x > a[r]) return -1;
	mid = (l + r) / 2; 
	if (a[mid] == x) return mid;
	else if (a[mid] < x) {
		if (mid + 1 <= r && x <= a[mid + 1]) return mid + 1;
		else return ceilSearch(a, mid + 1, r, x);
	}
	else {
		if (mid - 1 >= l && x > a[mid - 1]) return mid;
		else return ceilSearch(a, l, mid - 1, x);
	}
}


int main()
{
	int a[] = { 1, 2, 8, 10, 10, 12, 19 }, n = sizeof(a) / sizeof(a[0]), x = 20;
	int index = ceilSearch(a, 0, n - 1, x);
	if (index == -1) cout << "Ceiling of " << x << " doesn't exist in array ";
	else cout << "ceiling of " << x << " is " << a[index];

	return 0;
}

