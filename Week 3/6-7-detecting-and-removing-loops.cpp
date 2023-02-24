#include <iostream>
using namespace std;
  

struct node {
    int val;
    node* next;
};
  

void removeLoop(node* lnode, node* p)
{
    node* ptr1 = lnode;
    node* ptr2 = lnode;
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }
    ptr1 = p;
    ptr2 = p;
    for (i = 0; i < k; i++) ptr2 = ptr2->next;
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr2->next != ptr1) ptr2 = ptr2->next;
    ptr2->next = NULL;
}


int detectAndRemoveLoop(node* l)
{
    node *slow_p = l, *fast_p = l;
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            removeLoop(slow_p, l);
            return 1;
        }
    }
    return 0;
}
  
  
node* nn(int val)
{
    node* t = new node();
    t->val = val;
    t->next = NULL;
    return t;
}
  

int main()
{
    node* p = nn(50);
    p->next = nn(20);
    p->next->next = nn(15);
    p->next->next->next = nn(4);
    p->next->next->next->next = nn(10);
    p->next->next->next->next->next = p->next->next;
    detectAndRemoveLoop(p);
    cout << "Linked List after removing loop \n";
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}