#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node(int x) : val(x), next(NULL) {}
};

node* reverseInGroups(node* p, int k) {
    node* c = p;
    node* next = NULL;
    node* prev = NULL;
    int cnt = 0;
    while (c != NULL && cnt < k) {
        next = c->next;
        c->next = prev;
        prev = c;
        c = next;
        cnt++;
    }
    if (next != NULL) p->next = reverseInGroups(next, k);
    return prev;
}

void pl(node* p) {
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    node* p = new node(1);
    p->next = new node(2);
    p->next->next = new node(3);
    p->next->next->next = new node(4);
    p->next->next->next->next = new node(5);
    p->next->next->next->next->next = new node(6);
    p->next->next->next->next->next->next = new node(7);
    p->next->next->next->next->next->next->next = new node(8);

    cout << "Original List: ";
    pl(p);
    int k = 3;
    p = reverseInGroups(p, k);
    cout << "After Reversing in groups of " << k << ": ";
    pl(p);
    return 0;
}
