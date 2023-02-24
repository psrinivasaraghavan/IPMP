#include <iostream>
using namespace std;
 

struct node {
    int val;
    struct node* next;
    node(int val)
    {
        this->val = val;
        next = NULL;
    }
};
 
struct LinkedList {
    node* head;
    LinkedList() { head = NULL; }
 
    node* reverse(node* head)
    {
        if (head == NULL || head->next == NULL) return head;
        node* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
 
 
    void push(int val)
    {
        node* temp = new node(val);
        temp->next = head;
        head = temp;
    }
};
 

int main()
{
    LinkedList ll;
    ll.push(2);
    ll.push(4);
    ll.push(1);
    ll.push(8);
    ll.push(7);
    cout << "The linked list is:\n";
    struct node* t = ll.head;
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    ll.head = ll.reverse(ll.head);
    cout << "\nThe reversed linked list is:\n";
    t = ll.head;
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    return 0;
}