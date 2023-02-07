#include <iostream>
using namespace std;
bool isPalindrome(int a)
{
    int n = a, k, reversed = 0;
    while (a != 0) {
        k = a % 10;
        reversed = (reversed * 10) + k;
        a /= 10;
    }
    if (reversed == n) return true;
    else return false;
}
int main()
{
    int a = 873;
    while (!isPalindrome(a)) a += 1;
    cout << "Next Palindrome: "<<a;
    return 0;
}