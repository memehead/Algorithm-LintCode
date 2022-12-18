#include<iostream>
using namespace std;

// https://www.lintcode.com/problem/1360

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

bool process(TreeNode* left, TreeNode* right) {
	if (left == NULL && right == NULL) {
		return true;
	}
	if (left == NULL || right == NULL) {
		return false;
	}

	return left->val == right->val 
		&& process(left->left, right->right) 
		&& process(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	return process(root->left, root->right);
}