#include <bits/stdc++.h>
using namespace std;
#define N 4

struct MinHeapNode {
	int e, i, j;
};


void swap(MinHeapNode* x, MinHeapNode* y) {
	MinHeapNode temp = *x;
	*x = *y;
	*y = temp;
}


class MinHeap {
	MinHeapNode* ha;
	int heap_size;
public:
	MinHeap(MinHeapNode a[], int size);
	void MinHeapify(int);
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }
	MinHeapNode getMin() { return ha[0]; }
	void replaceMin(MinHeapNode x) {
		ha[0] = x;
		MinHeapify(0);
	}
};


int* mergeKArrays(int arr[][N], int K) {
	int* output = new int[N * K];
	MinHeapNode* ha = new MinHeapNode[K];
	for (int i = 0; i < K; i++) {
		ha[i].e = arr[i][0];
		ha[i].i = i;
		ha[i].j = 1;
	}
	MinHeap hp(ha, K);
	for (int count = 0; count < N * K; count++) {
		MinHeapNode root = hp.getMin();
		output[count] = root.e;
		if (root.j < N) {
			root.e = arr[root.i][root.j];
			root.j += 1;
		}
		else root.e = INT_MAX;
		hp.replaceMin(root);
	}

	return output;
}


MinHeap::MinHeap(MinHeapNode a[], int size)
{
	heap_size = size;
	ha = a;
	int i = (heap_size - 1) / 2;
	while (i >= 0) {
		MinHeapify(i);
		i--;
	}
}


void MinHeap::MinHeapify(int i) {
	int l = left(i), r = right(i), smallest = i;
	if (l < heap_size && ha[l].e < ha[i].e) smallest = l;
	if (r < heap_size && ha[r].e < ha[smallest].e) smallest = r;
	if (smallest != i) {
		swap(&ha[i], &ha[smallest]);
		MinHeapify(smallest);
	}
}


int main()
{
	int arr[][N] = { { 3, 7, 14, 34 }, { 5, 9, 18, 35 }, { 21, 43, 76, 90 } };
	int K = sizeof(arr) / sizeof(arr[0]);
	int* output = mergeKArrays(arr, K);
	cout << "Merged array is " << endl;
	for (int i = 0; i < K; i++) cout << arr[i] << " ";
	return 0;
}