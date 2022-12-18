#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// https://www.lintcode.com/problem/66/description

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

void process(TreeNode* root, vector<int>& res) {
	if (root == NULL) {
		return;
	}
	res.push_back(root->val);
	process(root->left, res);
	process(root->right, res);
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	if (root == NULL) {
		return res;
	}
	process(root, res);

	return res;
}

vector<int> preorderTraversal2(TreeNode* root) {
	vector<int> res;
	if (root == NULL) {
		return res;
	}

	stack<TreeNode*> stack;
	stack.push(root);

	while (!stack.empty()) {
		TreeNode* head = stack.top();
		stack.pop();
		res.push_back(head->val);

		if (head->right != NULL) {
			stack.push(head->right);
		}
		if (head->left != NULL) {
			stack.push(head->left);
		}
	}

	return res;
}