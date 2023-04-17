#include <bits/stdc++.h>
using namespace std;


unordered_map<int, int> memo;
int countTowers(int n) {
    if (n == 0) return 1;

    if (memo.find(n) != memo.end()) return memo[n];
    int count = 0;
    for (int i = 1; i <= n; i++) count += countTowers(n - i);
    memo[n] = count;
    return count;
}


int main() {
    int n;
    cout << "Enter the height of the tower (n): ";
    cin >> n;
    cout << "The number of different towers you can build is: " << countTowers(n) << endl;
    return 0;
}