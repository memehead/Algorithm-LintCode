# include<iostream>
# include<vector>
using namespace std;

// https://www.lintcode.com/problem/41/description

int maxSubArray(vector<int>& nums) {
	if (nums.empty()) {
		return INT_MIN;
	}

	int ans = nums[0];
	int pre = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		pre = max(nums[i], pre + nums[i]);
		ans = max(ans, pre);
	}

	return ans;
}