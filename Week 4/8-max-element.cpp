#include <iostream>
using namespace std;


int maxInBitonic(int a[], int l, int r)
{
	int n = r + 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if(a[mid] > a[mid+1] and a[mid] > a[mid-1]) return a[mid];
		else if (a[mid] < a[mid + 1]) l = mid + 1;
		else r = mid - 1;
	}

	return a[r];
}


int main()
{
	int a[] = { 19, 23, 43, 60, 8, 6, 4 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "The maximum element is " << maxInBitonic(a, 0, n - 1);
	return 0;
}

