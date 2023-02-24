#include <iostream>
using namespace std;


struct node {
    int val;
    node* next;
    node* arbit;
};


node* createNode(int val) {
    node* nn = new node;
    nn->val = val;
    nn->next = NULL;
    nn->arbit = NULL;
    return nn;
}


node* copyll(node* p) {
    if (p == NULL) return NULL;
    node* c = p;
    while (c != NULL) {
        node* nn = createNode(c->val);
        nn->next = c->next;
        c->next = nn;
        c = nn->next;
    }
    c = p;
    while (c != NULL) {
        if (c->arbit != NULL) c->next->arbit = c->arbit->next;
        c = c->next->next;
    }
    c = p;
    node* newHead = p->next;
    while (c != NULL) {
        node* t = c->next;
        c->next = t->next;
        if (t->next != NULL) t->next = t->next->next;
        c = c->next;
    }
    return newHead;
}


void pl(node* p) {
    node* c = p;
    while (c != NULL) {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;
}


int main() 
{
    node* p = createNode(1);
    p->next = createNode(2);
    p->next->next = createNode(3);
    p->next->next->next = createNode(4);

    p->arbit = p->next->next;
    p->next->arbit = p;
    p->next->next->arbit = p->next->next->next;
    p->next->next->next->arbit = p->next;

    cout << "Original linked list:" << endl;
    pl(p);
    node* newHead = copyll(p);
    cout << "Copied linked list:" << endl;
    pl(newHead);

    return 0;
}
