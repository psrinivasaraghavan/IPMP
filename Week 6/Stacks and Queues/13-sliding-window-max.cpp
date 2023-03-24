#include <bits/stdc++.h>
using namespace std;


struct node {
	int data;
	int maximum;
};


void insert(stack<node>& st2, int v)
{
	node other;
	other.data = v;
	if (st2.empty()) other.maximum = v;
	else {
		node front = st2.top();
		other.maximum = max(v, front.maximum);
	}
	st2.push(other);
	return;
}

void Delete (stack<node>& s1, stack<node>& st2)
{
	if (s1.size()) s1.pop();
	else {
		while (!st2.empty()) {
			node v = st2.top();
			insert(s1, v.data);
			st2.pop();
		}
		s1.pop();
	}
}

int get_max(stack<node>& s1, stack<node>& st2)
{
	int r = -1;
	if (s1.size()) r = max(r, s1.top().maximum);
	if (st2.size()) r = max(r, st2.top().maximum);
	return r;
}

vector<int> slidingMaximum(int a[], int b, int n)
{
	vector<int> r;
	stack<node> s1, st2;
	for (int i = 0; i < b - 1; i++) insert(st2, a[i]);
	for (int i = 0; i <= n - b; i++) {
		if (i - 1 >= 0) Delete (s1, st2);
		insert(st2, a[i + b - 1]);
		r.push_back(get_max(s1, st2));
	}
	return r;
}


int main()
{
	int a[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 }, n = sizeof(a) / sizeof(a[0]), K = 4;
	vector<int> r = slidingMaximum(a, K, n);
	for (auto x : r) cout << x << " ";
	return 0;
}