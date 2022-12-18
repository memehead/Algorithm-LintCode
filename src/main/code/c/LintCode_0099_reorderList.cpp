#include <iostream>

using namespace std;

// https://www.lintcode.com/problem/99

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

void reorderList(ListNode* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return;
	}
	ListNode* fast = head;
	ListNode* slow = head;

	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	// 反转右半部分链表
	ListNode* cur = slow;
	ListNode* pre = NULL;
	ListNode* temp = NULL;

	while (cur != NULL) {
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}

	cur = head; 
	ListNode* left = head->next;
	ListNode* right = NULL;
	while (left != NULL && pre != NULL) {
		cur->next = pre;
		right = pre;
		pre = pre->next;
		cur = right;

		cur->next = left;
		cur = left;
		left = left->next;
	}

	if (pre != NULL) {
		cur->next = pre;
		cur = pre;
		pre->next = NULL;
	}
}