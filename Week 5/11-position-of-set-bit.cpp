#include <bits/stdc++.h>
using namespace std;


unsigned int log2(unsigned int n)
{
	return (n > 1) ? 1 + log2(n / 2) : 0;
}


int isP2(unsigned n)
{
	return n && (!(n & (n - 1)));
}


int fp(unsigned n)
{
	if (!isP2(n)) return -1;
	return log2(n) + 1;
}


int main(void)
{
	int n = 0;
	int pos = fp(n);
	(pos == -1) ? cout<<"n = "<<n<<", Invalid number.\n" : cout<<"n = "<<n<<", Position :"<<pos<<" \n";
	n = 12;
	pos = fp(n);
	(pos == -1) ? cout<<"n = "<<n<<", Invalid number.\n" : cout<<"n = "<<n<<", Position :"<<pos<<" \n";
	n = 128;
	pos = fp(n);
	(pos == -1) ? cout<<"n = "<<n<<", Invalid number.\n" : cout<<"n = "<<n<<", Position :"<<pos<<" \n";
	return 0;
}

