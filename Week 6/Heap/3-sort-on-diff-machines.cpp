#include <iostream>
using namespace std;

struct listNode {
    int data;
    struct listNode * next;
};

struct minHeapNode {
    listNode * head;
};

struct MinHeap {
    int count;
    int capacity;
    minHeapNode * a;
};

MinHeap * createMinHeap(int capacity) {
    MinHeap * minHeap = new MinHeap;
    minHeap -> capacity = capacity;
    minHeap -> count = 0;
    minHeap -> a = new minHeapNode[minHeap -> capacity];
    return minHeap;
}

void push(listNode ** head_ref, int new_data) {
    listNode * nn = new listNode;
    nn -> data = new_data;
    nn -> next = ( * head_ref);
    ( * head_ref) = nn;
}

void swap(minHeapNode * a, minHeapNode * b) {
    minHeapNode temp = * a;
    * a = * b;
    * b = temp;
}

void minHeapify(MinHeap * minHeap, int idx) {
    int left, right, smallest;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
    smallest = idx;
    if (left < minHeap -> count && minHeap -> a[left].head -> data < minHeap -> a[smallest].head -> data)
        smallest = left;
    if (right < minHeap -> count && minHeap -> a[right].head -> data < minHeap -> a[smallest].head -> data)
        smallest = right;
    if (smallest != idx) {
        swap( & minHeap -> a[smallest], & minHeap -> a[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isEmpty(MinHeap * minHeap) {
    return (minHeap -> count == 0);
}

void buildMinHeap(MinHeap * minHeap) {
    int i, n;
    n = minHeap -> count - 1;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void populateMinHeap(MinHeap * minHeap, listNode * * a, int n) {
    for (int i = 0; i < n; ++i)
        minHeap -> a[minHeap -> count++].head = a[i];
    buildMinHeap(minHeap);
}

listNode * extractMin(MinHeap * minHeap) {
    if (isEmpty(minHeap)) return NULL;
    minHeapNode temp = minHeap -> a[0];
    if (temp.head -> next) minHeap -> a[0].head = temp.head -> next;
    else {
        minHeap -> a[0] = minHeap -> a[minHeap -> count - 1];
        --minHeap -> count;
    }
    minHeapify(minHeap, 0);
    return temp.head;
}

void externalSort(listNode * a[], int N) {
    MinHeap * minHeap = createMinHeap(N);
    populateMinHeap(minHeap, a, N);
    while (!isEmpty(minHeap)) {
        listNode * temp = extractMin(minHeap);
        cout << temp -> data;
    }
}

int main() {
    int N = 3;
    listNode * a[N];
    a[0] = NULL;
    push( & a[0], 50);
    push( & a[0], 40);
    push( & a[0], 30);
    a[1] = NULL;
    push( & a[1], 45);
    push( & a[1], 35);
    a[2] = NULL;
    push( & a[2], 100);
    push( & a[2], 80);
    push( & a[2], 70);
    push( & a[2], 60);
    push( & a[2], 10);
    externalSort(a, N);
    return 0;
}