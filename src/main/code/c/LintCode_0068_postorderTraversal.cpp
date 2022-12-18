#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// https://www.lintcode.com/problem/68

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
	process(root->right, res);
	res.push_back(root->val);
}

vector<int> postordertraversal(TreeNode* root) {
	vector<int> res;
	if (root == NULL) {
		return res;
	}
	process(root, res);

	return res;
}

vector<int> postorderTraversal2(TreeNode* root) {
	vector<int> res;
	if (root == NULL) {
		return res;
	}
	stack<TreeNode*> pushStack;
	stack<TreeNode*> popStack;

	pushStack.push(root);

	while (!pushStack.empty()) {
		TreeNode* head = pushStack.top();
		pushStack.pop();
		popStack.push(head);
		
		if (head->left != NULL) {
			pushStack.push(head->left);
		}
		if (head->right != NULL) {
			pushStack.push(head->right);
		}
	}

	while (!popStack.empty())
	{
		TreeNode* temp = popStack.top();
		popStack.pop();
		res.push_back(temp->val);
	}

	return res;
}