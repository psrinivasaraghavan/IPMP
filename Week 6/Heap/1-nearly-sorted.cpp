#include<bits/stdc++.h>
using namespace std;

void sortK(int a[], int n, int k)
{

	int size;
	size = (n == k) ? k : k + 1;
	priority_queue<int, vector<int>, greater<int>> pq(a, a + size);
	int i = 0;
	for (int i = k + 1; i < n; i++) {
		a[i++] = pq.top();
		pq.pop();
		pq.push(a[i]);
	}
	while (pq.empty() == false) {
		a[i++] = pq.top();
		pq.pop();
	}
}

void printArray(int a[], int size)
{
	for (int i = 0; i < size; i++) cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int k = 4, a[] = {10, 9, 8, 7, 4, 70, 60, 50}, n = sizeof(a) / sizeof(a[0]);
	sortK(a, n, k);
	printArray(a, n);
	return 0;
}