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
    LinkedList() 
    {
        head = NULL;
    }    

    void reverse()
    {
        node* curr = head;
        node *p = NULL, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = p;
            p = curr;
            curr = next;
        }
        head = p;
    }
 
    void push(int val)
    {
        node* t = new node(val);
        t->next = head;
        head = t;
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
    ll.reverse();
    cout << "\nThe reversed linked list is:\n";
    t = ll.head;
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    return 0;
}