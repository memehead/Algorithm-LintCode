#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/1609

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* middleNode(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	if (head->next->next == NULL) {
		return head->next;
	}

	ListNode* fast = head;
	ListNode* slow = head;

	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return fast->next == NULL ? slow : slow->next;
}
