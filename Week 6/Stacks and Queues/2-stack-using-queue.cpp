#include <bits/stdc++.h>
using namespace std;


class Stack {
	queue<int> q;

public:
	void push(int d, int c);
	void pop();
	int top();
	int size();
	bool empty();
};


void Stack::push(int d, int c)
{
	q.push(d);
	if (c <= 0) return;
	int x = q.front();
	q.pop();
	c--;
	Stack::push(x, c);
}


void Stack::pop()
{
	if (q.empty())
		cout << "No elements\n";
	else
		q.pop();
}


int Stack::top() { 
    return (q.empty()) ? -1 : q.front(); 
}


bool Stack::empty() { 
    return (q.empty()); 
}

int Stack::size() {
    return q.size();
}


int main()
{
	Stack st;
	st.push(4, st.size()); 
	st.push(5, st.size());
	st.push(6, st.size());
	cout << "The current size: " << st.size() << endl;
	cout << st.top() << "\n";
	st.pop();
	cout << st.top() << "\n";
	st.pop();
	cout << st.top() << "\n";
	cout << "The current size: " << st.size() << endl;
	return 0;
}