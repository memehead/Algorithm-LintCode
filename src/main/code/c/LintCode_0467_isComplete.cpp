#include<iostream>
#include <queue>
using namespace std;

// https://www.lintcode.com/problem/467

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


bool isComplete(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	queue<TreeNode*> queue;
	queue.push(root);
	bool flag = false;

	while (!queue.empty()) {
		TreeNode* head = queue.front();
		queue.pop();
		if ((flag && (head->left != NULL || head->right != NULL))
			|| (head->left == NULL && head->right != NULL)) {
			return false;
		}

		if (head->left != NULL) {
			queue.push(head->left);
		}
		if (head->right != NULL) {
			queue.push(head->right);
		}

		if (head->left == NULL || head->right == NULL) {
			flag = true;
		}
	}

	return true;
}