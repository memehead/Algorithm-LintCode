#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/1359/
class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

TreeNode* process(vector<int>& nums, int L, int R) {
    if (L > R) {
        return NULL;
    }
    if (L == R) {
        return new TreeNode(nums[L]);
    }

    int M = L + ((R - L) >> 1);
    TreeNode* head = new TreeNode(nums[M]);
    head->left = process(nums, L, M - 1);
    head->right = process(nums, M + 1, R);

    return head;
}

TreeNode* convertSortedArraytoBinarySearchTree(vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    };

    return process(nums, 0, nums.size() - 1);
}