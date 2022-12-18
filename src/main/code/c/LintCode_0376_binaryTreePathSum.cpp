#include <vector>
#include<iostream>

using namespace std;

// https://www.lintcode.com/problem/376

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

void process(TreeNode* head, int target, vector<vector<int>>& res, vector<int>& temp) {
	if (head->left == NULL && head->right == NULL) {
		if (target == 0) {
			vector<int> ans;
			for (int i = 0; i < temp.size(); i++) {
				ans.push_back(temp[i]);
			}
			res.push_back(ans);
			return;
		}
	}
	
	if (head->left != NULL) {
		temp.push_back(head->left->val);
		process(head->left, target - head->left->val, res, temp);
		temp.pop_back();
	}

	if (head->right != NULL) {
		temp.push_back(head->right->val);
		process(head->right, target - head->right->val, res, temp);
		temp.pop_back();
	}
}


vector<vector<int>> binaryTreePathSum(TreeNode* root, int target) {
	vector<vector<int>> res;
	if (root == NULL) {
		return res;
	}

	vector<int> temp;
	temp.push_back(root->val);
	process(root, target - root->val, res, temp);
	temp.pop_back();

	return res;
}