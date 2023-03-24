#include <bits/stdc++.h>
using namespace std;
#define MAX_TREE_HT 100


struct MinHeapNode {
    char d;
    unsigned freq;
    struct MinHeapNode * left, * right;
};


struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode ** a;
};


struct MinHeapNode * newNode(char d, unsigned freq) {
    struct MinHeapNode * t = (struct MinHeapNode * ) malloc(sizeof(struct MinHeapNode));
    t -> left = t -> right = NULL;
    t -> d = d;
    t -> freq = freq;
    return t;
}


struct MinHeap * createMinHeap(unsigned capacity) {
    struct MinHeap * minHeap = (struct MinHeap * ) malloc(sizeof(struct MinHeap));
    minHeap -> size = 0;
    minHeap -> capacity = capacity;
    minHeap -> a = (struct MinHeapNode ** ) malloc(
        minHeap -> capacity * sizeof(struct MinHeapNode * ));
    return minHeap;
}


void swapMinHeapNode(struct MinHeapNode ** a, struct MinHeapNode ** b) {
    struct MinHeapNode * t = * a;
    * a = * b;
    * b = t;
}


void minHeapify(struct MinHeap * minHeap, int i) {

    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < minHeap -> size && minHeap -> a[left] -> freq < minHeap -> a[smallest] -> freq)
        smallest = left;
    if (right < minHeap -> size && minHeap -> a[right] -> freq < minHeap -> a[smallest] -> freq)
        smallest = right;
    if (smallest != i) {
        swapMinHeapNode( & minHeap -> a[smallest], &  minHeap -> a[i]);
        minHeapify(minHeap, smallest);
    }
}


int isSizeOne(struct MinHeap * minHeap) {
    return (minHeap -> size == 1);
}


struct MinHeapNode * extractMin(struct MinHeap * minHeap) {
    struct MinHeapNode * t = minHeap -> a[0];
    minHeap -> a[0] = minHeap -> a[minHeap -> size - 1];
    --minHeap -> size;
    minHeapify(minHeap, 0);
    return t;
}


void insertMinHeap(struct MinHeap * minHeap, struct MinHeapNode * minHeapNode) {
    ++minHeap -> size;
    int i = minHeap -> size - 1;
    while (i && minHeapNode -> freq <  minHeap -> a[(i - 1) / 2] -> freq) {
        minHeap -> a[i] = minHeap -> a[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap -> a[i] = minHeapNode;
}


void buildMinHeap(struct MinHeap * minHeap) {
    int n = minHeap -> size - 1, i;
    for (i = (n - 1) / 2; i >= 0; --i) minHeapify(minHeap, i);
}


void printArr(int a[], int n) {
    int i;
    for (i = 0; i < n; ++i) cout << a[i];
    cout << "\n";
}


int isLeaf(struct MinHeapNode * root) {
    return !(root -> left) && !(root -> right);
}


struct MinHeap * createAndBuildMinHeap(char d[], int freq[], int size) {
    struct MinHeap * minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) minHeap -> a[i] = newNode(d[i], freq[i]);
    minHeap -> size = size;
    buildMinHeap(minHeap);
    return minHeap;
}


struct MinHeapNode * buildHuffmanTree(char d[], int freq[], int size) {
    struct MinHeapNode * left, * right, * top;
    struct MinHeap * minHeap = createAndBuildMinHeap(d, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left -> freq + right -> freq);
        top -> left = left;
        top -> right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}


void printCodes(struct MinHeapNode * root, int a[], int top) {
    if (root -> left) {
        a[top] = 0;
        printCodes(root -> left, a, top + 1);
    }
    if (root -> right) {
        a[top] = 1;
        printCodes(root -> right, a, top + 1);
    }
    if (isLeaf(root)) {
        cout << root -> d << ": ";
        printArr(a, top);
    }
}


void HuffmanCodes(char d[], int freq[], int size) {
    struct MinHeapNode * root = buildHuffmanTree(d, freq, size);
    int a[MAX_TREE_HT], top = 0;
    printCodes(root, a, top);
}


int main() {
    char a[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(a) / sizeof(a[0]);
    HuffmanCodes(a, freq, size);
    return 0;
}