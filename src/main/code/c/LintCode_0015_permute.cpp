# include<iostream>
# include<vector>
using namespace std;

// https://www.lintcode.com/problem/15/description
void swap(vector<int>& nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void process(vector<int>& nums, int index, vector<vector<int>>& res) {
	if (index == nums.size()) {
		vector<int> temp;
		for (int i = 0; i < nums.size(); i++) {
			temp.push_back(nums[i]);
		}
		res.push_back(temp);
		return;
	}
	for (int i = index; i < nums.size(); i++) {
		swap(nums, i, index);
		process(nums, index + 1, res);
		swap(nums, i, index);
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.empty()) {
		vector<int> temp;
		res.push_back(temp);
		return res;
	}

	process(nums, 0, res);
	
	return res;
}
