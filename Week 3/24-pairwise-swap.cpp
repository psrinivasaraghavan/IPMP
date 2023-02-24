#include <iostream>
using namespace std;


struct node {
    int val;
    node* next;
};


void insert(node** href, int new_data) {
    node* nn = new node;
    nn->val = new_data;
    nn->next = NULL;
    if (*href == NULL) {
        *href = nn;
        return;
    }
    node* last_node = *href;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = nn;
}


void printList(node* t) {
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}


void pairwiseSwap(node** href) {
    node* prev = *href;
    node* c = (*href)->next;
    *href = c;
    while (true) {
        node* next_node = c->next;
        c->next = prev;
        if (next_node == NULL || next_node->next == NULL) {
            prev->next = next_node;
            break;
        }
        prev->next = next_node->next;
        prev = next_node;
        c = prev->next;
    }
}


int main() 
{
    node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    cout << "Original List: ";
    printList(head);
    pairwiseSwap(&head);
    cout << "After Pairwise Swap: ";
    printList(head);

    return 0;
}
