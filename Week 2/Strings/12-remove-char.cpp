#include <bits/stdc++.h>
using namespace std;

int* getcount(string s2)
{
	int* count = (int*)calloc(sizeof(int), 256);
	for (int i = 0; i < s2.size(); i++) count[s2[i]]++;
	return count;
}


string removeChars(string s1, string s2)
{
	int* count = getcount(s2);
	string r;
	int i = 0;
	while (i < s1.size())
	{
		char t = s1[i];
		if (count[t] == 0) r.push_back(t);
		i++;
	}
	return r;
}


int main()
{
	string s1 = "check";
	string s2 = "bank";
	cout << removeChars(s1, s2) << endl;
}
