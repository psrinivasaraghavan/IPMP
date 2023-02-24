#include <iostream>
using namespace std;


struct node
{
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};


node* getIntersectionNode(node* p, node* q) 
{
    node *intersection = NULL;
    node *curA = p;
    node *curB = q;
    while (curA != NULL && curB != NULL) 
    {
        if (curA->val == curB->val) 
        {
            if (intersection == NULL || intersection->val != curA->val) intersection = new node(curA->val);
            curA = curA->next;
            curB = curB->next;
        } 
        else if (curA->val < curB->val) curA = curA->next;
        else curB = curB->next;
    }
    return intersection;
}


int main() {
    node* p = new node(1);
    p->next = new node(2);
    p->next->next = new node(3);
    p->next->next->next = new node(4);
    p->next->next->next->next = NULL;

    node* q = new node(2);
    q->next = new node(4);
    q->next->next = new node(6);
    q->next->next->next = NULL;

    node* intersection = getIntersectionNode(p, q);
    if (intersection != NULL) 
    {
        cout << "The intersection of the two sorted linked lists is: ";
        while (intersection != NULL) {
            cout << intersection->val << " ";
            intersection = intersection->next;
        }
        cout << endl;
    } 
    else cout << "The two sorted linked lists have no intersection." << endl;
    return 0;
}
