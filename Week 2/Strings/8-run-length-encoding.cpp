#include <iostream>
using namespace std;

void RLE(string s)
{
	int n = s.length();
	for (int i = 0; i < n; i++)
    {
		int c = 1;
		while (i < n - 1 && s[i] == s[i + 1]) {
			c++;
			i++;
		}
		cout << s[i] << c;
	}
}


int main()
{
	string s = "wwwwaaadexxxxxxywww";
	RLE(s);
	return 0;
}
