#include<bits/stdc++.h>
using namespace std;


class kStacks
{
	int *a;
	int *t; 
	int *next;
	int n, k;
	int free; 
public:
	kStacks(int k, int n);
	bool isFull() { return (free == -1); }
	void push(int item, int sn);
	int pop(int sn);
	bool isEmpty(int sn) { return (t[sn] == -1); }
};


kStacks::kStacks(int k1, int n1)
{
	k = k1, n = n1;
	a = new int[n];
	t = new int[k];
	next = new int[n];
	for (int i = 0; i < k; i++) t[i] = -1;
	free = 0;
	for (int i=0; i<n-1; i++) next[i] = i+1;
	next[n-1] = -1; 
}

void kStacks::push(int item, int sn)
{
	if (isFull())
	{
		cout << "Stack Overflow.\n";
		return;
	}
	int i = free;
	free = next[i];
	next[i] = t[sn];
	t[sn] = i;
	a[i] = item;
}

int kStacks::pop(int sn)
{
	if (isEmpty(sn))
	{
		cout << "Stack Underflow.\n";
		return INT_MAX;
	}
	int i = t[sn];
	t[sn] = next[i]; 
	next[i] = free;
	free = i;
	return a[i];
}


int main()
{
	int k = 3, n = 30;
	kStacks ks(k, n);
	ks.push(9, 0);
	ks.push(7, 0);
	ks.push(11, 0);
    ks.push(49, 1);
	ks.push(39, 1);
	ks.push(17, 1);
	ks.push(15, 2);
	ks.push(45, 2);
	cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
	return 0;
}