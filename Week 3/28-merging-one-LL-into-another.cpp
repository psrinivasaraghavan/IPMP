#include <iostream>
using namespace std;


struct node {
    int val;
    node* next;
};


void insert(node** href, int nd) {
    node* nn = new node;
    nn->val = nd;
    nn->next = NULL;
    if (*href == NULL) {
        *href = nn;
        return;
    }
    node* lnode = *href;
    while (lnode->next != NULL) lnode = lnode->next;
    lnode->next = nn;
}


void printList(node* t) {
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}


node* mergeAlternate(node* p, node* q) {
    if (p == NULL) return q;
    if (q == NULL) return p;
    node* res = p;
    while (p != NULL && q != NULL) {
        node* next1 = p->next;
        node* next2 = q->next;
        p->next = q;
        q->next = next1;
        p = next1;
        q = next2;
    }
    return res;
}


int main() 
{
    node* p = NULL;
    insert(&p, 1);
    insert(&p, 3);
    insert(&p, 5);
    insert(&p, 7);

    node* q = NULL;
    insert(&q, 2);
    insert(&q, 4);
    insert(&q, 6);

    cout << "List 1: ";
    printList(p);
    cout << "List 2: ";
    printList(q);
    node* merged_head = mergeAlternate(p, q);
    cout << "After Merging: ";
    printList(merged_head);

    return 0;
}
