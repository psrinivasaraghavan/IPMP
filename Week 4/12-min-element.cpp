#include <iostream>
using namespace std;


int findMin(int a[], int l, int r)
{
	if (r < l) return a[0];
	if (r == l) return a[l];
	int m = (r + l) / 2; 
	if (m < r && a[m + 1] < a[m]) return a[m + 1];
	if (m > l && a[m] < a[m - 1]) return a[m];
	if (a[r] > a[m]) return findMin(a, l, m - 1);
	return findMin(a, m + 1, r);
}


int main()
{
	int a[] = { 5, 6, 1, 2, 3, 4 }, n = sizeof(a) / sizeof(a[0]);
	cout << "The minimum element is " << findMin(a, 0, n - 1) << endl;
	return 0;
}

