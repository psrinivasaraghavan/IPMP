#include <bits/stdc++.h>
using namespace std;


void streamMed(int A[], int n) {
	priority_queue<int> g, s;
	for (int i = 0; i < n; i++) {
		s.push(A[i]);
		int t = s.top();
		s.pop();
		g.push(-1 * t);
		if (g.size() > s.size()) {
			t = g.top();
			g.pop();
			s.push(-1 * t);
		}
		if (g.size() != s.size()) cout << (double)s.top() << "\n";
		else cout << (double)((s.top() * 1.0 - g.top() * 1.0) / 2) << "\n";
	}
}


int main()
{
	int A[] = {  7, 9, 10, 6, 11, 4, 5, 15, 1, 3, 2, 8 };
	int N = sizeof(A) / sizeof(A[0]);
	streamMed(A, N);
	return 0;
}