#include <bits/stdc++.h>
using namespace std;

class node {
	public : int val;
	node* xnode;
};


node* Xor(node* x, node* y)
{
	return reinterpret_cast<node*> (reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}


void insert(node** href, int val)
{
	node* nn = new node();
	nn -> val = val;
	nn -> xnode = *href;
	if (*href != NULL) (*href)-> xnode = Xor(nn, (*href) -> xnode);
	*href = nn;
}


void printList(node* p)
{
	node* c = p;
	node* prev = NULL;
	node* next;
	cout << "The nodes of the linked list are: \n";
	while (c != NULL) {
		cout << c -> val << " ";
		next = Xor(prev, c -> xnode);
		prev = c;
		c = next;
	}
}


int main()
{
	node* p = NULL;
	insert(&p, 10);
	insert(&p, 100);
	insert(&p, 1000);
	insert(&p, 10000);
	printList(p);
	return 0;
}
