#include <iostream>
using namespace std;


int add(int a, int b)
{
	for (int i = 0; i < b; i++) a++;
	return a;
}


int main()
{
	int a = add(15, 16);
	cout << a;
	return 0;
}