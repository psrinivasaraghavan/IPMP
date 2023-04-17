#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}


int minMoves(int a, int b) {
    if (a == b) return 0;
    if (a < b) swap(a, b);
    int g = gcd(a, b), x = a / g, y = b / g, z = minMoves(x, y);
    return z + (g * (x + y - 2));
}


int main() {
    int a, b;
    cout << "Enter the dimensions of the rectangle (a b): ";
    cin >> a >> b;
    cout << "The minimum number of moves required is: " << minMoves(a, b) << endl;
    return 0;
}