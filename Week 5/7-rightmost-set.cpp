#include <iostream>
using namespace std;


int fun(unsigned int n)
{
	return n & (n - 1);
}


int main()
{
	int n = 15;
	cout<<"The number after unsetting the rightmost set bit is "<<fun(n);
	return 0;
}

