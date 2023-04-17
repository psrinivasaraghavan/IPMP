#include <bits/stdc++.h>
using namespace std;


int maxScore(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}


int main() {
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int score = maxScore(nums);
    cout << "The maximum possible score for the first player is: " << score << endl;
    return 0;
}