#include <iostream>
using namespace std;

void unique(string s)
{
	for (int i = 0; i < s.length(); i++) {
		if (s.find(s[i], s.find(s[i]) + 1) == string::npos)
        {
			cout << "The first non-repeating character is " << s[i];
			return;
		}
	}
	cout << "Either all characters are repeating or the string is empty.\n";
	return;
}


int main()
{
	string s = "check";
	unique(s);
    return 0;
}

