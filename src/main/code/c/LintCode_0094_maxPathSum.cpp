#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/94
class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Info {
   public:
    int maxSum;
    int startHeadMaxSum;

    Info(int maxSum, int startHeadMaxSum) {
        this->maxSum = maxSum;
        this->startHeadMaxSum = startHeadMaxSum;
    }
};

Info* process(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    Info* leftInfo = process(root->left);
    Info* rightInfo = process(root->right);

    int maxSum = root->val;
    if (leftInfo != NULL) {
        maxSum = max(maxSum, leftInfo->maxSum);
    }

    if (rightInfo != NULL) {
        maxSum = max(maxSum, rightInfo->maxSum);
    }

    int p1 = root->val;
    if (leftInfo != NULL && leftInfo->startHeadMaxSum > 0) {
        p1 += leftInfo->startHeadMaxSum;
    }
    int p2 = root->val;
    if (rightInfo != NULL && rightInfo->startHeadMaxSum > 0) {
        p2 += rightInfo->startHeadMaxSum;
    }
    int p3 = root->val;
    if (leftInfo != NULL && rightInfo != NULL &&
        leftInfo->startHeadMaxSum > 0 && rightInfo->startHeadMaxSum > 0) {
        p3 += (leftInfo->startHeadMaxSum + rightInfo->startHeadMaxSum);
    }

    maxSum = max(max(maxSum, p1), max(p2, p3));
    int startHeadMaxSum = max(p1, p2);

    return new Info(maxSum, startHeadMaxSum);
}

int maxPathSum(TreeNode* root) {
    if (root == NULL) {
        return INT_MIN;
    }

    return process(root)->maxSum;
}
