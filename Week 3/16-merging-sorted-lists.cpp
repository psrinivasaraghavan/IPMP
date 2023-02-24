#include <iostream>
using namespace std;


struct node {
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};


node* mergeTwoLists(node* p, node* q) 
{
    if (p == NULL) return q;
    if (q == NULL) return p;
    node* merged_head = NULL;
    node* merged_tail = NULL;
    while (p != NULL && q != NULL) 
    {
        if (p->val <= q->val) 
        {
            if (merged_head == NULL) merged_head = merged_tail = p;
            else 
            {
                merged_tail->next = p;
                merged_tail = p;
            }
            p = p->next;
        } 
        else 
        {
            if (merged_head == NULL) merged_head = merged_tail = q;
            else 
            {
                merged_tail->next = q;
                merged_tail = q;
            }
            q = q->next;
        }
    }
    if (p != NULL) merged_tail->next = p;
    else merged_tail->next = q;
    return merged_head;
}

int main()
{
    node* p = new node(1);
    p->next = new node(3);
    p->next->next = new node(5);
    p->next->next->next = NULL;
    node* q = new node(2);
    q->next = new node(4);
    q->next->next = new node(6);
    q->next->next->next = NULL;
    node* merged_head = mergeTwoLists(p, q);
    cout << "The merged linked list is: ";
    while (merged_head != NULL)
    {
        cout << merged_head->val << " ";
        merged_head = merged_head->next;
    }
    cout << endl;
    return 0;
}
