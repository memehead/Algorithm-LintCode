#include<iostream>
#include<vector>

using namespace std;

// https://www.lintcode.com/problem/148

void swap(vector<int>& nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void sortcolors(vector<int>& nums) {
	if (nums.empty() || nums.size() < 2) {
		return;
	}
	int r = nums.size();
	int l = -1;
	
	int i = 0;
	while (i < r) {
		if (nums[i] == 1) {
			i++;
		}
		else if(nums[i] == 0) {
			swap(nums, ++l, i++);
		}
		else {
			swap(nums, --r, i);
		}
	}
}