#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
};

void deleteNAfterM(node* p, int m, int n) {
    node* c = p;
    node* prev = NULL;
    int cnt;
    while (c != NULL) {
        for (cnt = 1; cnt <= m && c != NULL; cnt++) {
            prev = c;
            c = c->next;
        }
        for (cnt = 1; cnt <= n && c != NULL; cnt++) {
            node* temp = c;
            c = c->next;
            delete temp;
        }
        prev->next = c;
    }
}


void push(node** ptr, int val) {
    node* nn = new node;
    nn->val = val;
    nn->next = *ptr;
    *ptr = nn;
}


void printList(node* p) {
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}


int main() 
{
    node* p = NULL;
    for (int i = 10; i >= 1; i--) push(&p, i);
    cout << "Original linked list:" << endl;
    printList(p);
    deleteNAfterM(p, 3, 2);
    cout << "Modified linked list:" << endl;
    printList(p);
    return 0;
}
