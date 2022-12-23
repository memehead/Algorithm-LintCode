#include <iostream>
#include <set>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/16
void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void process(vector<int>& nums, int index, vector<vector<int>>& res) {
    if (index == nums.size()) {
        res.push_back(nums);
        return;
    }
    set<int> set;
    for (int i = index; i < nums.size(); i++) {
        if (set.find(nums[i]) == set.end()) {
            set.insert(nums[i]);
            swap(nums, i, index);
            process(nums, index + 1, res);
            swap(nums, i, index);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) {
        vector<int> ans;
        res.push_back(ans);
        return res;
    }

    process(nums, 0, res);

    return res;
}