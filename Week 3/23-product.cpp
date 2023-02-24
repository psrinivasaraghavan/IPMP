#include <iostream>
using namespace std;


struct node {
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};


int listToInt(node* l)
{
    int n = 0;
    while (l != NULL) 
    {
        n = n * 10 + l->val;
        l = l->next;
    }
    return n;
}


node* intToList(int n) 
{
    if (n == 0) return new node(0);
    node* p = NULL;
    node* r = NULL;
    while (n != 0)
    {
        int digit = n % 10;
        if (p == NULL) p = r = new node(digit);
        else 
        {
            r->next = new node(digit);
            r = r->next;
        }
        n /= 10;
    }
    return p;
}


node* multiplyLists(node* p, node* q) 
{
    int num1 = listToInt(p);
    int num2 = listToInt(q);
    int product = num1 * num2;
    node* r = intToList(product);
    return r;
}


void printList(node* p) 
{
    while (p != NULL)
    {
        cout << p->val;
        p = p->next;
    }
    cout << endl;
}

int main() 
{
    node* p = new node(2);
    p->next = new node(4);
    p->next->next = new node(3);
    node* q = new node(5);
    q->next = new node(6);
    q->next->next = new node(4);
    node* r = multiplyLists(p, q);
    cout << "The product of the two numbers is: ";
    printList(r);
    return 0;
}
