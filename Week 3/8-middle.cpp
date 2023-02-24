#include <iostream>
using namespace std;


struct node
{
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};


node* middleNode(node* p) 
{
    node *s = p, *f = p;
    while (f != NULL && f->next != NULL) {
        s = s->next;
        f = f->next->next;
    }
    return s;
}


int main() 
{
    node* p = new node(50);
    p->next = new node(40);
    p->next->next = new node(20);
    p->next->next->next = new node(10);
    p->next->next->next->next = new node(30);
    p->next->next->next->next->next = NULL;
    node* middle = middleNode(p);
    cout << "The middle node of the linked list is " << middle->val << endl;
    return 0;
}
