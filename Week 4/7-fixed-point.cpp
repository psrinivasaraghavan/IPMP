#include <iostream>
using namespace std;


int bsearch(int a[], int l, int r)
{
	if (r >= l) {
		int m = (l + r) / 2;
		if (m == a[m]) return m;
		int res = -1;
		if (m + 1 <= a[r]) res = bsearch(a, (m + 1), r);
		if (res != -1) return res;
		if (m - 1 >= a[l]) return bsearch(a, l, (m - 1));
	}
	return -1;
}


int main()
{
	int a[] = {-20, -4, -2, 2, 3, 5, 30, 45, 70}, n = sizeof(a) / sizeof(a[0]);
	cout << "Fixed Point is " << bsearch(a, 0, n - 1);
	return 0;
}