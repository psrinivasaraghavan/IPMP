#include <iostream>
using namespace std;


struct node {
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};


node* merge(node* p, node* q) 
{
    if (p == NULL)  return q;
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


node* divide(node* p) {
    node* s = p;
    node* f = p;
    node* prev = NULL;
    while (f != NULL && f->next != NULL) 
    {
        prev = s;
        s = s->next;
        f = f->next->next;
    }
    if (prev != NULL) prev->next = NULL;
    return s;
}


node* mergeSort(node* p)
{
    if (p == NULL || p->next == NULL) return p;
    node* mid = divide(p);
    node* left = mergeSort(p);
    node* right = mergeSort(mid);
    return merge(left, right);
}


void print(node* p) 
{
    while (p != NULL) 
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() 
{
    node* p = new node(3);
    p->next = new node(5);
    p->next->next = new node(4);
    p->next->next->next = new node(2);
    p->next->next->next->next = new node(1);
    p->next->next->next->next->next = NULL;
    cout << "The unsorted linked list is: ";
    print(p);
    node* r = mergeSort(p);
    cout << "The sorted linked list is: ";
    print(r);
    return 0;
}
