#include <bits/stdc++.h>
using namespace std;


int bsearch(int a[], int l, int r, int val)
{
	if (r < l) return -1;
	int mid = (l + r) / 2;
	if (val == a[mid]) return mid;
	if (val > a[mid]) return bsearch(a, (mid + 1), r, val);
	return bsearch(a, l, (mid - 1), val);
}


int findPivot(int a[], int l, int r)
{
	if (r < l) return -1;
	if (r == l) return l;
	int mid = (l + r) / 2;
	if (mid < r && a[mid] > a[mid + 1]) return mid;
	if (mid > l && a[mid] < a[mid - 1]) return (mid - 1);
	if (a[l] >= a[mid]) return findPivot(a, l, mid - 1);
	return findPivot(a, mid + 1, r);
}


int pivotedbsearch(int a[], int n, int val)
{
	int pivot = findPivot(a, 0, n - 1);
	if (pivot == -1) return bsearch(a, 0, n - 1, val);
	if (a[pivot] == val) return pivot;
	if (a[0] <= val) return bsearch(a, 0, pivot - 1, val);
	return bsearch(a, pivot + 1, n - 1, val);
}


int main()
{
	int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int val = 3;
	cout << "Index of the element is : " << pivotedbsearch(arr1, n, val);
	return 0;
}
