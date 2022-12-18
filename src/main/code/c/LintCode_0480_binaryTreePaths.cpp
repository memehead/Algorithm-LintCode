#include<iostream>
#include <vector>
#include <string>
using namespace std;

// https://www.lintcode.com/problem/480

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

string vector2String(vector<int>& path) {
	string res = "";
	for (int i = 0; i < path.size(); i++) {
		res.append(to_string(path[i]));

		if (i != path.size() - 1) {
			res.append("->");
		}
	}
	return res;
}

void process(TreeNode* head, vector<string>& res, vector<int>& path) {
	if (head->left == NULL && head->right == NULL) {
		path.push_back(head->val);
		res.push_back(vector2String(path));
		path.pop_back();
		return;
	}

	path.push_back(head->val);
	if (head->left != NULL) {
		process(head->left, res, path);
	}
	if (head->right != NULL) {
		process(head->right, res, path);
	}
	path.pop_back();
}


vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> res;

	if (root == NULL) {
		return res;
	}

	vector<int> path;
	process(root, res, path);

	return res;
}