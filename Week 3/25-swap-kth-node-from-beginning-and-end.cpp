#include <iostream>
using namespace std;


struct node {
    int val;
    struct node* next;
};


void insert(node** p, int val) {
    node* nn = new node();
    nn->val = val;
    nn->next = NULL;
    if (*p == NULL) {
        *p = nn;
        return;
    }
    node* last = *p;
    while (last->next != NULL) last = last->next;
    last->next = nn;
}


int length(node* p) {
    int l = 0;
    while (p != NULL) {
        l++;
        p = p->next;
    }
    return l;
}


void swapKthNode(node** p, int k) {
    int n = length(*p);
    if (n < k || 2*k - 1 == n) return;
    node* prevX = NULL;
    node* currX = *p;
    for (int i = 1; i < k; i++) {
        prevX = currX;
        currX = currX->next;
    }
    node* prevY = NULL;
    node* currY = *p;
    for (int i = 1; i <= n-k; i++) {
        prevY = currY;
        currY = currY->next;
    }
    if (prevX != NULL) prevX->next = currY;
    else *p = currY;
    if (prevY != NULL) prevY->next = currX;
    else *p = currX;
    node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}


void printList(node* p) {
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    node* p = NULL;
    insert(&p, 1);
    insert(&p, 2);
    insert(&p, 3);
    insert(&p, 4);
    insert(&p, 5);
    insert(&p, 6);
    insert(&p, 7);

    cout << "Original List: ";
    printList(p);
    swapKthNode(&p, 2);
    cout << "After Swapping: ";
    printList(p);
    return 0;
}
