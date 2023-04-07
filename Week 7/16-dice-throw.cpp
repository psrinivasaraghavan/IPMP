#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;
const int maxs = 155;
int dp[maxn][maxs];


int diceThrow(int dice, int sides, int sum) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= dice; i++) {
        for (int j = 1; j <= sum; j++) {
            for (int k = 1; k <= sides && k <= j; k++) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    return dp[dice][sum];
}


int main() {
    int dice, sides, sum;
    cout << "Enter the number of dice: ";
    cin >> dice;
    cout << "Enter the number of sides: ";
    cin >> sides;
    cout << "Enter the desired sum: ";
    cin >> sum;
    cout << "Number of ways to get the desired sum: " << diceThrow(dice, sides, sum) << endl;
    return 0;
}