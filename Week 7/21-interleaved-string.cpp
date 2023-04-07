#include <bits/stdc++.h>
using namespace std;


bool isInterleaved(string s1, string s2, string s3) {
    int m = s1.length(), n = s2.length(), p = s3.length();
    if (m + n != p) return false;
    bool dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) if (s2[i - 1] == s3[i - 1] && dp[0][i - 1]) dp[0][i] = true;

    for (int i = 1; i <= m; i++) if (s1[i - 1] == s3[i - 1] && dp[i - 1][0]) dp[i][0] = true;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int k = i + j - 1;
            if (s1[i - 1] == s3[k] && dp[i - 1][j]) {
                dp[i][j] = true;
            }
            else if (s2[j - 1] == s3[k] && dp[i][j - 1]) {
                dp[i][j] = true;
            }
        }
    }
    return dp[m][n];
}


int main() {
    string s1 = "abc", s2 = "def", s3 = "adebcf";
    if (isInterleaved(s1, s2, s3)) cout << s3 << " is interleaved of " << s1 << " and " << s2 << endl;
    else cout << s3 << " is not interleaved of " << s1 << " and " << s2 << endl;
    return 0;
}