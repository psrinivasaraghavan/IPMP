#include <bits/stdc++.h>
using namespace std;


bool isPowerofTwo(long long n)
{
	if(n<0) return false;
	return (n != 0) && ((n & (n - 1)) == 0);
}


int main()
{
	isPowerofTwo(256)? cout << "Yes\n" : cout << "No\n";
	isPowerofTwo(12)? cout << "Yes\n" : cout << "No\n";
	return 0;
}
