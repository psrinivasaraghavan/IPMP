#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int dp[maxn][maxn];


int longestCommonSubstring(string s1, string s2) {
    int ans = 0;
    for (int i = 0; i <= s1.length(); i++) dp[i][0] = 0;
    for (int j = 0; j <= s2.length(); j++) dp[0][j] = 0;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int ans = longestCommonSubstring(s1, s2);
    cout << "Length of longest common substring: " << ans << endl;
    return 0;
}
