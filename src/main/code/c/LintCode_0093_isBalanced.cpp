#include <iostream>

using namespace std;

// https://www.lintcode.com/problem/93

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

class Info {
public:
	int height;
	bool isBalanced;

	Info(int hegiht, bool isBalanced) {
		this->height = hegiht;
		this->isBalanced = isBalanced;
	}
};

Info* process(TreeNode* head) {
	if (head == NULL) {
		return new Info(0, true);
	}

	Info* leftInfo = process(head->left);
	Info* rightInfo = process(head->right);

	int height = 1;
	height += max(leftInfo->height, rightInfo->height);

	bool isBalanced = false;

	if (leftInfo->isBalanced && rightInfo->isBalanced
		&& abs(leftInfo->height - rightInfo->height) <= 1) {
		isBalanced = true;
	}

	return new Info(height, isBalanced);
}


bool isBalanced(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	return process(root)->isBalanced;
}