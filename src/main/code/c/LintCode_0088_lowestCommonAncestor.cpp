#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/88
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

class Info {
   public:
    bool findA;
    bool findB;
    TreeNode* ans;
    Info(bool findA, bool findB, TreeNode* ans) {
        this->findA = findA;
        this->findB = findB;
        this->ans = ans;
    }
};

Info* process(TreeNode* root, TreeNode* A, TreeNode* B) {
    if (root == NULL) {
        return new Info(false, false, NULL);
    }
    Info* leftInfo = process(root->left, A, B);
    Info* rightInfo = process(root->right, A, B);

    bool findA = root == A || leftInfo->findA || rightInfo->findA;
    bool findB = root == B || leftInfo->findB || rightInfo->findB;

    TreeNode* ans = NULL;
    if (leftInfo->ans != NULL) {
        ans = leftInfo->ans;
    } else if (rightInfo->ans != NULL) {
        ans = rightInfo->ans;
    } else {
        if (findA && findB) {
            ans = root;
        }
    }

    return new Info(findA, findB, ans);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* A, TreeNode* B) {
    if (root == NULL) {
        return root;
    }

    return process(root, A, B)->ans;
}