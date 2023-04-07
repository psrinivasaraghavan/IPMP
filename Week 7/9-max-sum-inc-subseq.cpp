#include <bits/stdc++.h>
using namespace std;


int maxSumIS(int a[], int n)
{
	int i, j, max = 0;
	int msis[n];
	for (i = 0; i < n; i++ ) msis[i] = a[i];
	for (i = 1; i < n; i++) for (j = 0; j < i; j++) if (a[i] > a[j] && msis[i] < msis[j] + a[i]) msis[i] = msis[j] + a[i];
	for (i = 0; i < n; i++) if (max < msis[i]) max = msis[i];
	return max;
}


int main()
{
	int a[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Sum of maximum sum increasing subsequence is " << maxSumIS(a, n) << endl;
	return 0;
}