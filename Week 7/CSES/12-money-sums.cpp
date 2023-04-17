#include <bits/stdc++.h>
using namespace std;


void findSums(vector<int>& coins, int index, int sum, vector<int>& result) {
    if (index == coins.size()) {
        result.push_back(sum);
        return;
    }
    findSums(coins, index + 1, sum, result);
    findSums(coins, index + 1, sum + coins[index], result);
}


int main() {
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the values of the coins: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> result;
    findSums(coins, 0, 0, result);
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    cout << "All possible sums of money that can be created are: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}