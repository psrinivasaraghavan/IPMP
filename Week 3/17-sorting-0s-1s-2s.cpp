#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
};

void sortList(node* p) {
    int cnt[3] = {0, 0, 0};
    node* c = p;
    while (c != NULL) {
        cnt[c->val]++;
        c = c->next;
    }
    c = p;
    int i = 0;
    while (c != NULL) {
        if (cnt[i] == 0) {
            i++;
        } else {
            c->val = i;
            cnt[i]--;
            c = c->next;
        }
    }
}


void push(node** headRef, int val) {
    node* nn = new node;
    nn->val = val;
    nn->next = *headRef;
    *headRef = nn;
}


void printList(node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() 
{
    node* p = NULL;
    push(&p, 2);
    push(&p, 0);
    push(&p, 1);
    push(&p, 2);
    push(&p, 1);
    push(&p, 0);
    push(&p, 1);
    cout << "The original linked list:" << endl;
    printList(p);
    sortList(p);
    cout << "The sorted linked list:" << endl;
    printList(p);
    return 0;
}
