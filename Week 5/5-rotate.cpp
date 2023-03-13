#include<iostream>
using namespace std;
#define bits 32


int leftRotate(int n, unsigned int d)
{
	return (n << d)|(n >> (bits - d));
}


int rightRotate(int n, unsigned int d)
{
	return (n >> d)|(n << (bits - d));
}


int main()
{
	int n = 12, d = 3;
	cout << "Left Rotation of " << n << " by " << d << " is ";
	cout << leftRotate(n, d);
	cout << "\nRight Rotation of " << n << " by " << d << " is ";
	cout << rightRotate(n, d);
	return 0;
}

