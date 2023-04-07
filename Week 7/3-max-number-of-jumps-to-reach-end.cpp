#include <bits/stdc++.h>
using namespace std;


int maxNumberOfJumps(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 0);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        int minJumps = INT_MAX;
        for (int j = i + 1; j <= i + a[i] && j < n; j++) {
            minJumps = min(minJumps, dp[j]);
        }
        dp[i] = (minJumps == INT_MAX) ? INT_MAX : minJumps + 1;
    }
    return dp[0];
}


int main() {
    vector<int> a = {2, 3, 1, 1, 4};
    int maxJumps = maxNumberOfJumps(a);
    cout << "Maximum number of jumps to reach end of array is: " << maxJumps << endl;
    return 0;
}
