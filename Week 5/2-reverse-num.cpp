#include <bits/stdc++.h>
using namespace std;

unsigned int reverseBits(unsigned int num)
{
	unsigned int nb = sizeof(num) * 8;
	unsigned int rnum = 0;
	int i;
	for (i = 0; i < nb; i++) if ((num & (1 << i))) rnum |= 1 << ((nb - 1) - i);
	return rnum;
}


int main()
{
	unsigned int x = 2147483648;
	cout << reverseBits(x);
	return 0;
}
