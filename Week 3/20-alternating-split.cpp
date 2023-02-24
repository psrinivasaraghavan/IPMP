#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
};


void push(node** href, int new_data) {
    node* nn = new node;
    nn->val = new_data;
    nn->next = *href;
    *href = nn;
}


void pl(node* t) {
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
}


void alternatingSplit(node* p, node** a, node** b) {
    node* c = p;
    node* aTail = NULL;
    node* bTail = NULL;
    while (c != NULL) {
        if ((*a) == NULL) {
            (*a) = c;
            aTail = (*a);
        } else {
            aTail->next = c;
            aTail = aTail->next;
        }
        c = c->next;

        if (c != NULL) {
            if ((*b) == NULL) {
                (*b) = c;
                bTail = (*b);
            } else {
                bTail->next = c;
                bTail = bTail->next;
            }
            c = c->next;
        }
    }
    if (aTail != NULL) aTail->next = NULL;
    if (bTail != NULL) bTail->next = NULL;
}


int main() {
    node* p = NULL;
    push(&p, 6);
    push(&p, 5);
    push(&p, 4);
    push(&p, 3);
    push(&p, 2);
    push(&p, 1);
    cout << "Original Linked List: ";
    pl(p);
    node* a = NULL;
    node* b = NULL;
    alternatingSplit(p, &a, &b);
    cout << "\n\nAlternating split of the given Linked List: ";
    cout << "\nFirst List: ";
    pl(a);
    cout << "\nSecond List: ";
    pl(b);
    return 0;
}
