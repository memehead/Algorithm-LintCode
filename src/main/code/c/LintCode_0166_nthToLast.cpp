#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/166

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};


ListNode* nthToLast(ListNode* head, int n) {
	if (head == NULL) {
		return NULL;
	}

	ListNode* fast = head;
	while (n != 0) {
		fast = fast->next;
		n--;
	}

	ListNode* slow = head;
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}