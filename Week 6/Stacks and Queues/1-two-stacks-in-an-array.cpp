#include <bits/stdc++.h>
using namespace std;


class twoStacks {
	int* a;
	int s, t1, t2;

public:
	twoStacks(int n)
	{
		s = n;
		a = new int[n];
		t1 = -1;
		t2 = s;
	}

	void push1(int x)
	{
		if (t1 < t2 - 1) {
			t1++;
			a[t1] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	void push2(int x)
	{
		if (t1 < t2 - 1) {
			t2--;
			a[t2] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}


	int pop1()
	{
		if (t1 >= 0) {
			int x = a[t1];
			t1--;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}

	
	int pop2()
	{
		if (t2 < s) {
			int x = a[t2];
			t2++;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};


int main()
{
	twoStacks ts(5);
	ts.push1(15);
	ts.push2(11);
	ts.push2(13);
	ts.push1(19);
	ts.push2(73);
	cout << "Popped element from stack1 is " << ts.pop1();
	ts.push2(27);
	cout << "\nPopped element from stack2 is " << ts.pop2();
	return 0;
}