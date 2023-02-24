#include <iostream>
#include <unordered_set>
using namespace std;


struct node 
{
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};


node *getIntersectionNode(node *p, node *q)
{
    unordered_set<node*> v;
    node *cur = p;
    while (cur != NULL) {
        v.insert(cur);
        cur = cur->next;
    }
    cur = q;
    while (cur != NULL) {
        if (v.find(cur) != v.end()) return cur;
        cur = cur->next;
    }
    return NULL;
}


int main() 
{
    node* p = new node(1);
    p->next = new node(2);
    p->next->next = new node(3);
    p->next->next->next = new node(4);
    p->next->next->next->next = new node(5);
    p->next->next->next->next->next = NULL;

    node* q = new node(6);
    q->next = new node(7);
    q->next->next = p->next->next->next;
    q->next->next->next = p->next->next->next->next;
    q->next->next->next->next = NULL;

    node* intersection = getIntersectionNode(p, q);
    if (intersection != NULL) cout << "The intersection point of the two linked lists is " << intersection->val << endl;
    else cout << "The two linked lists do not intersect." << endl;
    return 0;
}
