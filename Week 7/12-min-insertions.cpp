#include <bits/stdc++.h>
using namespace std;


int min_insertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}


int main() {
    string s;
    cin >> s;
    int min_insertions_val = min_insertions(s);
    cout << "Minimum Insertions: " << min_insertions_val << endl;
    return 0;
}