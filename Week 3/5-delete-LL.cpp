#include <iostream>
using namespace std;
  

struct node {
    int val;
    node* next;
};
  

void deleteList(node** head)
{
    node* curr = *head;
    node* next = NULL;
    while (curr != NULL) 
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}
  

void push(node** head, int val)
{
    node* new_node = new node();
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}
  

int main()
{
    node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    cout << "Now the linked list will be deleted.\n";
    deleteList(&head);
    cout << "The linked list has been deleted.\n";
}