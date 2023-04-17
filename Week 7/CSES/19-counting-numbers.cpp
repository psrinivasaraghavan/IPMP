#include <bits/stdc++.h>
using namespace std;


int dp[20][10][10];


int main() {
    int a, b;
    cin >> a >> b;
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
            dp[1][j][k] = 1;
        }
    }
    for (int i = 2; i <= 19; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int x = 0; x < 10; x++) {
                    if (x != j && x != k) {
                        dp[i][j][k] += dp[i-1][x][j];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = 1; j < 10; j++) {
        for (int k = 0; k < j; k++) {
            ans += dp[19][j][k];
        }
    }
    for (int i = 2; i <= 18; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 0; k < j; k++) {
                ans -= dp[i][j][k];
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 20; i++) {
        if (a <= ans && ans <= b) cnt++;
        ans *= 10;
    }
    cout << cnt << endl;
    return 0;
}