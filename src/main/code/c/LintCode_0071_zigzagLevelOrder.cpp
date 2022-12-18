#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://www.lintcode.com/problem/71

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> res;
	vector<int> temp;
	if (root == NULL) {
		return res;
	}

	queue<TreeNode*> queue;
	queue.push(root);

	int flag = 1;
	TreeNode* curEnd = root;
	TreeNode* nextEnd = NULL;

	while (!queue.empty()) {
		TreeNode* head = queue.front();
		queue.pop();
		if (flag == 1) {
			temp.push_back(head->val);
		}
		else {
			temp.insert(temp.begin(), head->val);
		}

		if (head->left != NULL) {
			queue.push(head->left);
			nextEnd = head->left;
		}
		if (head->right != NULL) {
			queue.push(head->right);
			nextEnd = head->right;
		}

		if (curEnd == head) {
			res.push_back(temp);
			temp.clear();
			flag = flag == 1 ? 2 : 1;
			curEnd = nextEnd;
		}
	}

	return res;
}