#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// https://www.lintcode.com/problem/70/

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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> res;
	vector<int> temp;
	if (root == NULL) {
		return res;
	}

	queue<TreeNode*> queue;
	queue.push(root);

	TreeNode* cur = root;
	TreeNode* nextEnd = NULL;

	while (!queue.empty()) {
		TreeNode* head = queue.front();
		queue.pop();
		temp.push_back(head->val);
		if (head->left != NULL) {
			queue.push(head->left);
			nextEnd = head->left;
		}
		if (head->right != NULL) {
			queue.push(head->right);
			nextEnd = head->right;
		}

		if (cur == head) {
			res.push_back(temp);
			temp.clear();
			cur = nextEnd;
		}
	}
	reverse(res.begin(), res.end());

	return res;
}