#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int a[maxn], dp[maxn];


int longestIncreasingSubsequence(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) dp[i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main() {
    int n, ans;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ans = longestIncreasingSubsequence(n);
    cout << "The length of the longest increasing subsequence: " << ans << endl;
    return 0;
}