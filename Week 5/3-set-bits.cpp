#include <bits/stdc++.h>
using namespace std;


unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n) n &= (n - 1), count++;
    return count;
}


int main()
{
	int i = 15;
	cout << countSetBits(i);
	return 0;
}
