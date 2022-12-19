# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

// https://www.lintcode.com/problem/17/description
void process(vector<int>& nums, int index, vector<int>& temp, vector<vector<int>>& res) {
	if (index == nums.size()) {
		res.push_back(temp);
		return;
	}
	process(nums, index + 1, temp, res);

	temp.push_back(nums[index]);
	process(nums, index + 1, temp, res);
	temp.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> temp;

	if (nums.empty()) {
		res.push_back(temp);
		return res;
	}
	sort(nums.begin(), nums.end());

	process(nums, 0, temp, res);

	return res;
}
