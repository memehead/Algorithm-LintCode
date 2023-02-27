#include<iostream>
#include <queue>

using namespace std;

// https://www.lintcode.com/problem/939
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

int kthfloorNode(TreeNode* root, int k) {
	if (root == NULL) {
		return 0;
	}

	queue<TreeNode*> queue;
	queue.push(root);

	int curLevel = 0;
	TreeNode* curEnd = root;
	TreeNode* nextEnd = NULL;
	int count = 0;


	while (!queue.empty()) {
		TreeNode* head = queue.front();
		queue.pop();

		if (curLevel == k - 1) {
			count++;
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

	return count;
}
