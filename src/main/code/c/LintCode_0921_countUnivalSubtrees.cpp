#include<iostream>
using namespace std;

// https://www.lintcode.com/problem/921

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
	bool isSame;
	int sameCounts;

	Info(bool isSame, int sameCounts) {
		this->isSame = isSame;
		this->sameCounts = sameCounts;
	}
};

Info* process0921(TreeNode* head) {
	if (head == NULL) {
		return new Info(true, 0);
	}

	Info* leftInfo = process0921(head->left);
	Info* rightInfo = process0921(head->right);

	int sameCounts = 0;
	bool isSame = false;

	if (leftInfo->isSame && rightInfo->isSame) {
		if (head->left == NULL && head->right == NULL) {
			isSame = true;
			sameCounts = 1;
		}
		else if (head->left == NULL) {
			isSame = head->right->val == head->val ? true : false;
			sameCounts =  head->right->val == head->val ? 1 + rightInfo->sameCounts : rightInfo->sameCounts;
		}
		else if (head->right == NULL) {
			isSame = head->left->val == head->val ? true : false;
			sameCounts = head->left->val == head->val ? 1 + leftInfo->sameCounts : leftInfo->sameCounts;
		}
		else {
			bool flag = head->right->val == head->val && head->left->val == head->val && head->left->val && head->right->val;
			isSame = flag ? true : false;
			sameCounts = flag ? leftInfo->sameCounts + rightInfo->sameCounts + 1: leftInfo->sameCounts + rightInfo->sameCounts;
		}
	}
	else {
		sameCounts = leftInfo->sameCounts + rightInfo->sameCounts;
	}

	return new Info(isSame, sameCounts);
}

int countUnivalSubtrees(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	return process0921(root)->sameCounts;
}
