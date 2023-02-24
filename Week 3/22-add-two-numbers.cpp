#include <iostream>
using namespace std;


struct node {
    int val;
    node* next;
};


void insert(node** head_ref, int new_data) {
    node* new_node = new node;
    new_node->val = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    node* last_node = *head_ref;
    while (last_node->next != NULL) last_node = last_node->next;
    last_node->next = new_node;
}


void printList(node* t) {
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}


node* addLists(node* p, node* q) {
    node* result = NULL;
    node* prev = NULL;
    node* t = NULL;
    int carry = 0;
    while (p != NULL || q != NULL) 
    {
        int sum = carry + (p ? p->val : 0) + (q ? q->val : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        t = new node;
        t->val = sum;
        t->next = NULL;
        if (result == NULL) result = t;
        else prev->next = t;
        prev = t;
        if (p) p = p->next;
        if (q) q = q->next;
    }

    if (carry > 0) 
    {
        t = new node;
        t->val = carry;
        t->next = NULL;
        prev->next = t;
    }

    return result;
}

int main() 
{
    node* p = NULL;
    node* q = NULL;
    insert(&p, 3);
    insert(&p, 4);
    insert(&p, 2);
    insert(&q, 4);
    insert(&q, 6);
    insert(&q, 5);

    node* result = addLists(p, q);
    cout << "Result: ";
    printList(result);
    return 0;
}
