#include <bits/stdc++.h>
using namespace std;


void greaterElement(int a[], int n)
{
	stack<int> s;
	s.push(a[0]);
	for (int i = 1; i < n; i++) {
		if (s.empty()) {
			s.push(a[i]);
			continue;
		}
		while (s.empty() == false && s.top() < a[i]) {
			cout << s.top() << " --> " << a[i] << endl;
			s.pop();
		}
		s.push(a[i]);
	}
	while (s.empty() == false) {
		cout << s.top() << " --> " << -1 << endl;
		s.pop();
	}
}


int main()
{
	int a[] = {1, 5, 2, 3}, n = sizeof(a) / sizeof(a[0]);
	greaterElement(a, n);
	return 0;
}