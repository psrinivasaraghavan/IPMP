#include <bits/stdc++.h>
using namespace std;


unsigned int getFirstSetBitPos(int n)
{
    return log2(n & -n) + 1;
}


int main()
{
	int n = 15;
	cout << getFirstSetBitPos(n);
	return 0;
}