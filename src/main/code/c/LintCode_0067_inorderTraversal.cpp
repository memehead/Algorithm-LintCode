#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// https://www.lintcode.com/problem/67

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
	process(root->left, res);
	res.push_back(root->val);
	process(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	if (root == NULL) {
		return res;
	}
	process(root, res);

	return res;
}

vector<int> inorderTraversal2(TreeNode* root) {
	vector<int> res;
	if (root == NULL) {
		return res;
	}
	stack<TreeNode*> stack;
	
	while (!stack.empty() || root != NULL) {
		if (root != NULL) {
			stack.push(root);
			root = root->left;
		}
		else {
			root = stack.top();
			res.push_back(root->val);
			stack.pop();
			root = root->right;
		}
	}

	return res;
}