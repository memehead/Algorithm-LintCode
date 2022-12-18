#include <iostream>

using namespace std;

// https://www.lintcode.com/problem/95

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
	int maxVal; 
	int minVal;
	bool isBST;

	Info(int max, int min, bool isBST) {
		this->maxVal = max;
		this->minVal = min;
		this->isBST = isBST;
	}
};

Info* process0095(TreeNode* head) {
	if (head == NULL) {
		return NULL;
	}

	Info* leftInfo = process0095(head->left);
	Info* rightInfo = process0095(head->right);

	int maxValue = head->val;
	int minValue = head->val;

	if (leftInfo != NULL) {
		maxValue = max(maxValue, leftInfo->maxVal);
		minValue = min(minValue, leftInfo->minVal);
	}

	if (rightInfo != NULL) {
		maxValue = max(maxValue, rightInfo->maxVal);
		minValue = min(minValue, rightInfo->minVal);
	}

	bool isBST = true;
	if (leftInfo != NULL && !leftInfo->isBST) {
		isBST = false;
	}

	if (rightInfo != NULL && !rightInfo->isBST) {
		isBST = false;
	}

	if (leftInfo != NULL && head->val <= leftInfo->maxVal) {
		isBST = false;
	}
	if (rightInfo != NULL && head->val >= rightInfo->minVal) {
		isBST = false;
	}

	return new Info(maxValue, minValue, isBST);
}


bool isValidBST(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	return process0095(root)->isBST;
}