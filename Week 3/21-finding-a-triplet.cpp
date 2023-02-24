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
    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }
    node* last_node = *head_ref;
    while (last_node->next != NULL) last_node = last_node->next;
    last_node->next = new_node;
}


void findTriplet(node* head1, node* head2, node* head3, int sum) {
    node* a = head1;
    while (a != NULL) 
    {
        node* b = head2;
        node* c = head3;
        while (b != NULL && c != NULL) 
        {
            int triplet_sum = a->val + b->val + c->val;
            if (triplet_sum == sum) {
                cout << "Triplet found: " << a->val << ", " << b->val << ", " << c->val << endl;
                return;
            } 
            else if (triplet_sum < sum) b = b->next;
            else c = c->next;
        }
        a = a->next;
    }

    cout << "Triplet not found" << endl;
}


int main() 
{
    node* head1 = NULL;
    node* head2 = NULL;
    node* head3 = NULL;
    insert(&head1, 1);
    insert(&head1, 2);
    insert(&head1, 3);
    insert(&head1, 4);
    insert(&head1, 5);
    insert(&head2, 2);
    insert(&head2, 3);
    insert(&head2, 4);
    insert(&head2, 5);
    insert(&head2, 6);
    insert(&head3, 3);
    insert(&head3, 4);
    insert(&head3, 5);
    insert(&head3, 6);
    insert(&head3, 7);
    int sum = 14;
    findTriplet(head1, head2, head3, sum);
    return 0;
}
