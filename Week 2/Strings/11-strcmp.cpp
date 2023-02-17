#include <iostream>
using namespace std;


int STRCMP(string s1, string s2)
{
	int i;
	for (i = 0; s1[i] && s2[i]; ++i)
	{
		if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i]) continue;
		else break;
	}
	if (s1[i] == s2[i]) return 0;
	if ((s1[i] | 32) < (s2[i] | 32)) return -1;
	return 1;
}


int main()
{
	cout << STRCMP("check", "banana") <<endl;
	cout << STRCMP("", "ABCD")<<endl;
	cout << STRCMP("ABCD", "z")<<endl;
	cout << STRCMP("ABC", "abcdEghe")<<endl;
	return 0;
}

