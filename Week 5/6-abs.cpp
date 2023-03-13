#include <bits/stdc++.h>
using namespace std;
#define bit 8


unsigned int getAbs(int n)
{
	int const mask = n >> (sizeof(int) * bit - 1);
	return ((n + mask) ^ mask);
}


int main()
{
	int n = -4;
	cout << "The absolute value of " << n << " is " << getAbs(n);
	return 0;
}