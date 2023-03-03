#include <bits/stdc++.h>
using namespace std;


int LongestIncreasingSubsequenceLength(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
    vector<int> tail(nums.size(), 0);
	int l = 1;
	tail[0] = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		auto b = tail.begin(), e = tail.begin() + l;
		auto it = lower_bound(b, e, nums[i]);
		if (it == tail.begin() + l) tail[l++] = nums[i];
		else *it = nums[i];
	}
	return l;
}


int main()
{
	vector<int> nums{4, 5, 7, 8, 11, 9, 10, 12};
	cout << "The length of the longest increasing subsequence is " << LongestIncreasingSubsequenceLength(nums);
	return 0;
}
