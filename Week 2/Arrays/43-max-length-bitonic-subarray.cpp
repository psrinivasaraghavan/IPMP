#include <iostream>
using namespace std;

int bitonic(int a[], int n)
{
	int inc[n];
	int dec[n], i, max;
	inc[0] = 1;
	dec[n-1] = 1;
	for (i = 1; i < n; i++)
	inc[i] = (a[i] >= a[i-1])? inc[i-1] + 1: 1;
	for (i = n-2; i >= 0; i--)
	dec[i] = (a[i] >= a[i+1])? dec[i+1] + 1: 1;
	max = inc[0] + dec[0] - 1;
	for (i = 1; i < n; i++) if (inc[i] + dec[i] - 1 > max) max = inc[i] + dec[i] - 1;
	return max;
}


int main()
{
	int a[] = {12, 4, 78, 90, 45, 23};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "The length of maximum length bitonic subarray is " << bitonic(a, n);
	return 0;
}

