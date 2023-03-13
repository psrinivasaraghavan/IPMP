#include <bits/stdc++.h>
using namespace std;


int countSetBits(int n)
{
	int count = 0;
	while (n > 0) count++, n &= (n - 1);
	return count;
}


int main()
{
	int a = 15, b = 16;
	cout << countSetBits(a ^ b) << endl;
	return 0;
}

