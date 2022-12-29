#include<iostream>
using namespace std;

// https://www.lintcode.com/problem/1524
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

TreeNode* searchBST(TreeNode* root, int val) {
	if (root == NULL) {
		return NULL;
	}

	TreeNode* res = NULL;
	if (root->val > val) {
		res = searchBST(root->left, val);
	}
	else if (root->val < val) {
		res = searchBST(root->right, val);
	}
	else {
		res = root;
	}

	return res;
}
