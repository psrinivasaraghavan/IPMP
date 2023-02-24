#include <iostream>
using namespace std;


struct node {
    int val;
    node* next;
};


void insert(node** head_ref, int new_data) {
    node* nn = new node;
    nn->val = new_data;
    nn->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = nn;
        return;
    }

    node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = nn;
}


void printList(node* p) {
    while (p != NULL)
    {
        cout << p->val;
        p = p->next;
    }
    cout << endl;
}

node* swapOddEven(node* head) {
    if (head == NULL || head->next == NULL) return head;
    node* onode = head;
    node* enode = head->next;
    node* even_head = enode;

    while (onode != NULL && enode != NULL) {
        onode->next = enode->next;
        if (onode->next != NULL) enode->next = onode->next->next;
        else enode->next = NULL;
        onode = onode->next;
        enode = enode->next;
    }

    onode = head;
    while (onode->next != NULL) onode = onode->next;
    onode->next = even_head;
    return head;
}

int main() 
{
    node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    cout << "Original List: ";
    printList(head);
    head = swapOddEven(head);
    cout << "After Swapping: ";
    printList(head);
    return 0;
}
