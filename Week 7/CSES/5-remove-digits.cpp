#include <bits/stdc++.h>
using namespace std;


int numSteps(int n) {
    string s = to_string(n);
    int steps = 0;
    while (n != 0) {
        int digit = n % 10;
        n /= 10;
        if (digit != 0) {
            n -= digit;
            steps++;
        }
    }
    return steps;
}


int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int steps = numSteps(n);
    cout << "The number of steps required to make the number equal to 0 is " << steps << endl;
    return 0;
}