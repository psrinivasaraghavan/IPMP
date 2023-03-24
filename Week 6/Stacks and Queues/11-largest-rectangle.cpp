#include <bits/stdc++.h>
using namespace std;


int getMaxArea(int a[], int n)
{
	stack<int> s;
	s.push(-1);
	int area = a[0];
	int i = 0;
	vector<int> ls(n, -1), rs(n, n);
	while (i < n) {
		while (!s.empty() && s.top() != -1
			&& a[s.top()] > a[i]) {
			rs[s.top()] = i;
			s.pop();
		}
		if (i > 0 && a[i] == a[i - 1]) ls[i] = ls[i - 1];
		else ls[i] = s.top();
		s.push(i);
		i++;
	}
	for (int j = 0; j < n; j++) area = max(area, a[j] * (rs[j] - ls[j] - 1));
	return area;
}


int main()
{
	int h[] = { 6, 2, 5, 4, 5, 1, 6 },  n = sizeof(h) / sizeof(h[0]);
	cout << "maxArea = " << getMaxArea(h, n) << endl;
	return 0;
}
