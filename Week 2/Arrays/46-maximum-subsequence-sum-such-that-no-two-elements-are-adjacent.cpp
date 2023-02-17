#include <iostream>
#include <vector>
using namespace std;

int rec(vector<int>& nums, int ind, vector<int>& dp)
{
	if (ind >= nums.size()) return 0;
	if (dp[ind] != -1) return dp[ind];
	return dp[ind] = max(rec(nums, ind + 1, dp), nums[ind] + rec(nums, ind + 2, dp));
}


int findMaxSum(vector<int>& nums, int n)
{
	vector<int> dp(n + 1, -1);
	return rec(nums, 0, dp);
}


int main()
{
	vector<int> a { 20, 25, 40, 30, 10, 8 };
	cout << findMaxSum(a, a.size()) << endl;
	return 0;
}
