#include <bits/stdc++.h>
using namespace std;


class node
{
	public:
	int val;
	node* next; 
};


node* XOR (node *a, node *b)
{
	return reinterpret_cast<node *> (reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}


void insert(node **href, int val)
{
	node *nn = new node();
	nn->val = val;
	nn->next = *href;
	if (*href != NULL) (*href)->next = XOR(nn, (*href)->next);
	*href = nn;
}


void pl(node *p)
{
	node *c = p;
	node *prev = NULL;
	node *next;
	cout << "Following are the nodes of the linked list: \n";
	while (c != NULL)
	{
		cout << c->val << " ";
		next = XOR(prev, c->next);
		prev = c;
		c = next;
	}
}


int main ()
{
	node *p = NULL;
	insert(&p, 10);
	insert(&p, 20);
	insert(&p, 30);
	insert(&p, 40);
	pl(p);
	return 0;
}
