#include<iostream>
#include <queue>

using namespace std;

// https://www.lintcode.com/problem/482

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

int levelSum(TreeNode* root, int level) {
	if (root == NULL) {
		return 0;
	}
	if (level == 1) {
		return root->val;
	}

	int res = 0;
	queue<TreeNode*> queue;
	queue.push(root);

	int curLevel = 1;
	TreeNode* curEnd = root;
	TreeNode* nextEnd = NULL;
	while (!queue.empty()) {
		TreeNode* head = queue.front();
		queue.pop();

		if (curLevel == level) {
			res += head->val;
		}

		if (head->left != NULL) {
			queue.push(head->left);
			nextEnd = head->left;
		}

		if (head->right != NULL) {
			queue.push(head->right);
			nextEnd = head->right;
		}

		if (head == curEnd) {
			curLevel++;
			curEnd = nextEnd;
		}
	}

	return res;
}