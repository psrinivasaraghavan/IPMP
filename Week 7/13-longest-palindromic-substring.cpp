#include <bits/stdc++.h>
using namespace std;


string longest_palindrome(string s) {
    int n = s.size(),max_len = 1, start = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) dp[i][i] = true;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2)  dp[i][j] = true;
                 else dp[i][j] = dp[i+1][j-1];
            }
            if (dp[i][j] && len > max_len) {
                max_len = len;
                start = i;
            }
        }
    }
    return s.substr(start, max_len);
}


int main() {
    string s;
    cin >> s;
    cout << "Longest Palindromic Substring: " << longest_palindrome(s) << endl;
    return 0;
}