#include <iostream>

using namespace std;

// https://www.lintcode.com/problem/372

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

void deleteNode(ListNode* node) {
	if (node == NULL || node->next == NULL) {
		return;
	}

	node->val = node->next->val;
	node->next = node->next->next;
}										