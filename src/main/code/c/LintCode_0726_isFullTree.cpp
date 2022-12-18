#include<iostream>
#include <queue>
using namespace std;

// https://www.lintcode.com/problem/726

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
	int nodeNums;

	Info(int height, int nodeNums) {
		this->height = height;
		this->nodeNums = nodeNums;
	}
};

Info* process0726(TreeNode* head) {
	if (head == NULL) {
		return new Info(0, 0);
	}
	Info* leftInfo = process0726(head->left);
	Info* rightInfo = process0726(head->right);

	int height = max(leftInfo->height, rightInfo->height) + 1;
	int nodeNums = leftInfo->nodeNums + rightInfo->nodeNums + 1;

	return new Info(height, nodeNums);
}


// 国内的满二叉树和国外的满二叉树的定义还不一样
bool isFullTree(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	Info* res = process0726(root);
	return ((1 << res->height) - 1) == res->nodeNums;
}

// 国外的满二叉树
bool isFullTree2(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	queue<TreeNode*> queue;
	queue.push(root);

	while (!queue.empty()) {
		TreeNode* head = queue.front();
		queue.pop();

		if ((head->left != NULL && head->right != NULL)
			|| (head->left == NULL && head->right == NULL)) {
			if (head->left != NULL) {
				queue.push(head->left);
			}
			if (head->right != NULL) {
				queue.push(head->right);
			}
		}
		else {
			return false;
		}
	}

	return true;
}