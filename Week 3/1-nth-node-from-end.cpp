#include <iostream>
using namespace std;


struct node {
	int val;
	struct node* next;
};


void NodefromTheEnd(struct node* head, int n)
{
    int len = 0, i;
    node* t = head;
    while (t != NULL) {
        t = t->next;
        len++;
    }
    if (len < n) return;
    t = head;
    for (i = 1; i < len - n + 1; i++) t = t->next;
    printf("%d", t->val);
    return;
}


void push(struct node** head, int val)
{
    node* nn = new node();
    nn->val = val;
    nn->next = *head;
    *head = nn;
}


int main()
{
	struct node* head = NULL;
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
	push(&head, 39);
	NodefromTheEnd(head, 3);
	return 0;
}
