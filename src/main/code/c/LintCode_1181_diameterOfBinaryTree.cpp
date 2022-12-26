#include<iostream>
using namespace std;

// https://www.lintcode.com/problem/1181

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
	int distance;

	Info(int height, int distance) {
		this->height = height;
		this->distance = distance;
	}
};

Info* process(TreeNode* head) {
	if (head == NULL) {
		return new Info(0, 0);
	}

	Info* leftInfo = process(head->left);
	Info* rightInfo = process(head->right);

	int height = max(leftInfo->height, rightInfo->height) + 1;
	int distance = max(max(leftInfo->distance, rightInfo->distance), leftInfo->height + rightInfo->height + 1);

	return new Info(height, distance);
}


int diameterOfBinaryTree(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	return process(root)->distance;
}
