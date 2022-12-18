#include<iostream>
using namespace std;

// https://www.lintcode.com/problem/469

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

bool isIdentical(TreeNode* a, TreeNode* b) {
	if (a == NULL && b == NULL) {
		return true;
	}
	if (a == NULL || b == NULL) {
		return false;
	}

	if (a->val == b->val) {
		return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
	}

	return false;
}