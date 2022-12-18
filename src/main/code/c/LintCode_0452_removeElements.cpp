#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/452

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};
ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	}

	ListNode* cur = head;
	while (cur != NULL && cur->val == val) {
		cur = cur->next;
	}
	if (cur == NULL) {
		return NULL;
	}

	ListNode* res = cur;
	ListNode* pre = cur;
	cur = cur->next;

	while (cur != NULL) {
		if (cur->val != val) {
			pre->next = cur;
			pre = cur;
		}
		cur = cur->next;
	}
	pre->next = cur;

	return res;
}