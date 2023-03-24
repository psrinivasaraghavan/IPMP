#include <bits/stdc++.h>
using namespace std;

class LRUCache {
	list<int> dq;
	unordered_map<int, list<int>::iterator> ma;
	int s;

public:
	LRUCache(int);
	void ref(int);
	void disp();
};


LRUCache::LRUCache(int n) { s = n; }
void LRUCache::ref(int x)
{
	if (ma.find(x) == ma.end()) {
		if (dq.size() == s) {
			int last = dq.back();
			dq.pop_back();
			ma.erase(last);
		}
	}
	else dq.erase(ma[x]);
	dq.push_front(x);
	ma[x] = dq.begin();
}


void LRUCache::disp()
{
	for (auto it = dq.begin(); it != dq.end(); it++) cout << (*it) << " ";
	cout << endl;
}

int main()
{
	LRUCache ca(4);
	ca.ref(1);
	ca.ref(2);
	ca.ref(3);
	ca.ref(1);
	ca.ref(4);
	ca.ref(5);
	ca.disp();
	return 0;
}
