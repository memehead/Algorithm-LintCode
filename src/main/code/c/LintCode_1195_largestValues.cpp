#include<iostream>
#include <queue>
using namespace std;

// https://www.lintcode.com/problem/1195

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

vector<int> largestValues(TreeNode* root) {
	vector<int> res;
	if (root == NULL) {
		return res;
	}

	queue<TreeNode*> queue;
	queue.push(root);

	int maxVal = INT_MIN;
	TreeNode* curEnd = root;
	TreeNode* nextEnd = NULL;

	while (!queue.empty()) {
		TreeNode* head = queue.front();
		queue.pop();
		maxVal = max(maxVal, head->val);

		if (head->left != NULL) {
			queue.push(head->left);
			nextEnd = head->left;
		}

		if (head->right != NULL) {
			queue.push(head->right);
			nextEnd = head->right;
		}

		if (curEnd == head) {
			res.push_back(maxVal);
			maxVal = INT_MIN;
			curEnd = nextEnd;
		}
	}

	return res;
}