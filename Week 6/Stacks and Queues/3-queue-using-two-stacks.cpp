#include <bits/stdc++.h>
using namespace std;

struct Queue {
	stack<int> s;

	
	void eq(int x)
	{
		s.push(x);
	}


	int dq()
	{
		if (s.empty()) {
			cout << "Q is empty";
			exit(0);
		}
		int x = s.top();
		s.pop();
		if (s.empty()) return x;
		int item = dq();
		s.push(x);
		return item;
	}
};


int main()
{
	Queue q;
	q.eq(20);
	q.eq(10);
	q.eq(50);
	cout << q.dq() << '\n';
	cout << q.dq() << '\n';
	cout << q.dq() << '\n';
	return 0;
}