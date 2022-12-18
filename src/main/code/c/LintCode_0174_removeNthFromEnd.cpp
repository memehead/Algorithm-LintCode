#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/174

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == NULL) {
		return NULL;
	}

	ListNode* fast = head;

	while (n != 0) {
		fast = fast->next;
		n--;
	}

	if (fast == NULL) {
		return head->next;
	}
	ListNode* slow = head;
	ListNode* slowPre = NULL;

	while (fast != NULL) {
		fast = fast->next;
		slowPre = slow;
		slow = slow->next;
	}

	slowPre->next = slow->next;
	
	return head;
}