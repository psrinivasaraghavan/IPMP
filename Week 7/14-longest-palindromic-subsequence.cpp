#include <bits/stdc++.h>
using namespace std;


int longest_palindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}


int main() {
    string s;
    cin >> s;
    cout << "Length of Longest Palindromic Subsequence: " << longest_palindrome(s) << endl;
    return 0;
}