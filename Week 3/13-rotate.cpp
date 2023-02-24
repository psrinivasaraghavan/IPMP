#include <iostream>
using namespace std;


struct node 
{
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};


node* rotateRight(node* p, int k) 
{
    if (p == NULL || p->next == NULL || k == 0) return p;
    int len = 1;
    node *tl = p;
    while (tl->next != NULL) 
    {
        tl = tl->next;
        len++;
    }
    k = k % len;
    if (k == 0) return p;
    node *new_tail = p;
    for (int i = 1; i < len - k; i++) new_tail = new_tail->next;
    node *nhead = new_tail->next;
    new_tail->next = NULL;
    tl->next = p;
    return nhead;
}


int main() 
{
    node* p = new node(1);
    p->next = new node(2);
    p->next->next = new node(3);
    p->next->next->next = new node(4);
    p->next->next->next->next = new node(5);
    p->next->next->next->next->next = NULL;

    int k = 2;
    node* rlist = rotateRight(p, k);
    cout << "The linked list after rotating by " << k << " nodes is: ";
    while (rlist != NULL) 
    {
        cout << rlist->val << " ";
        rlist = rlist->next;
    }
    cout << endl;
    return 0;
}
