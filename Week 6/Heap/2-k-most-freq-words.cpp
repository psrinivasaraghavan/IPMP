#include <bits/stdc++.h>
using namespace std;
# define MAX_CHARS 26
# define MAX_WORD_SIZE 30


struct TreeNode {
    bool isEnd;
    unsigned freq;
    int indexMinHeap;
    TreeNode * child[MAX_CHARS];
};


struct MinHeapNode {
    TreeNode * root;
    unsigned freq;
    char * word;
};


struct MinHeap {
    unsigned cap;
    int cnt;
    MinHeapNode * a;
};


TreeNode * newTreeNode() {
    TreeNode * trieNode = new TreeNode;
    trieNode -> isEnd = 0;
    trieNode -> freq = 0;
    trieNode -> indexMinHeap = -1;
    for (int i = 0; i < MAX_CHARS; ++i) trieNode -> child[i] = NULL;
    return trieNode;
}


MinHeap * createMinHeap(int cap) {
    MinHeap * minHeap = new MinHeap;
    minHeap -> cap = cap;
    minHeap -> cnt = 0;
    minHeap -> a = new MinHeapNode[minHeap -> cap];
    return minHeap;
}


void swapMinHeapNodes(MinHeapNode * a, MinHeapNode * b) {
    MinHeapNode temp = * a;
    * a = * b;
    * b = temp;
}


void minHeapify(MinHeap * minHeap, int idx) {
    int left, right, smallest;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
    smallest = idx;
    if (left < minHeap -> cnt && minHeap -> a[left].freq < minHeap -> a[smallest].freq)
        smallest = left;
    if (right < minHeap -> cnt && minHeap -> a[right].freq < minHeap -> a[smallest].freq)
        smallest = right;
    if (smallest != idx) {
        minHeap -> a[smallest].root -> indexMinHeap = idx;
        minHeap -> a[idx].root -> indexMinHeap = smallest;
        swapMinHeapNodes( & minHeap -> a[smallest], & minHeap -> a[idx]);
        minHeapify(minHeap, smallest);
    }
}


void buildMinHeap(MinHeap * minHeap) {
    int i, n = minHeap -> cnt - 1;
    for (i = (n - 1) / 2; i >= 0; --i) minHeapify(minHeap, i);
}


void insertInMinHeap(MinHeap * minHeap, TreeNode ** root,
    const char * word) {
    if (( * root) -> indexMinHeap != -1) {
        ++(minHeap -> a[( * root) -> indexMinHeap].freq);
        minHeapify(minHeap, ( * root) -> indexMinHeap);
    } else if (minHeap -> cnt < minHeap -> cap) {
        int cnt = minHeap -> cnt;
        minHeap -> a[cnt].freq = ( * root) -> freq;
        minHeap -> a[cnt].word = new char[strlen(word) + 1];
        strcpy(minHeap -> a[cnt].word, word);

        minHeap -> a[cnt].root = * root;
        ( * root) -> indexMinHeap = minHeap -> cnt;

        ++(minHeap -> cnt);
        buildMinHeap(minHeap);
    } else if (( * root) -> freq > minHeap -> a[0].freq) {
        minHeap -> a[0].root -> indexMinHeap = -1;
        minHeap -> a[0].root = * root;
        minHeap -> a[0].root -> indexMinHeap = 0;
        minHeap -> a[0].freq = ( * root) -> freq;
        delete[] minHeap -> a[0].word;
        minHeap -> a[0].word = new char[strlen(word) + 1];
        strcpy(minHeap -> a[0].word, word);
        minHeapify(minHeap, 0);
    }
}


void insertUtil(TreeNode ** root, MinHeap * minHeap,
    const char * word,
        const char * dupWord) {
    if ( * root == NULL) * root = newTreeNode();
    if ( * word != '\0') insertUtil( & (( * root) -> child[tolower( * word) - 97]), minHeap, word + 1, dupWord);
    else {
        if (( * root) -> isEnd) ++(( * root) -> freq);
        else {
            ( * root) -> isEnd = 1;
            ( * root) -> freq = 1;
        }
        insertInMinHeap(minHeap, root, dupWord);
    }
}


void insertTrieAndHeap(const char * word, TreeNode ** root, MinHeap * minHeap) {
    insertUtil(root, minHeap, word, word);
}


void displayMinHeap(MinHeap * minHeap) {

    for (int i = 0; i < minHeap -> cnt; ++i) {
        printf("%s : %d\n", minHeap -> a[i].word, minHeap -> a[i].freq);
    }
}


void printKMostFreq(FILE * fp, int k) {
    MinHeap * minHeap = createMinHeap(k);
    TreeNode * root = NULL;
    char buffer[MAX_WORD_SIZE];
    while (fscanf(fp, "%s", buffer) != EOF) insertTrieAndHeap(buffer, & root, minHeap);
    displayMinHeap(minHeap);
}


int main() {
    int k = 5;
    FILE * fp = fopen("file.txt", "r");
    if (fp == NULL) printf("File doesn't exist ");
    else printKMostFreq(fp, k);
    return 0;
}