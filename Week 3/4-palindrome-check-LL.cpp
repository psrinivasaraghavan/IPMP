#include <iostream>
#include <vector>
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
    node* p;
    LinkedList() 
    {
        p = NULL;
    }    
    void reverse()
    {
        node* c = p;
        node *p = NULL, *next = NULL;
        while (c != NULL) {
            next = c->next;
            c->next = p;
            p = c;
            c = next;
        }
        p = p;
    }
 
    void push(int val)
    {
        node* t = new node(val);
        t->next = p;
        p = t;
    }
};
 

int main()
{
    LinkedList ll;
    ll.push(3);
    ll.push(4);
    ll.push(5);
    ll.push(4);
    ll.push(3);
    vector<int> v;
    struct node* t = ll.p;
    while (t != NULL) {
        v.push_back(t->val);
        t = t->next;
    }
    ll.reverse();
    t = ll.p;
    for(int i = 0; i < v.size() ; i++) 
    {
        if(v[i] != t->val) break;
        else 
        {
            t = t-> next;
            continue;
        }
    }
    if(t != NULL) cout << "It is not a palindromic linked list.\n";
    if(t == NULL) cout << "It is a palindromic linked list.\n";
    return 0;
}