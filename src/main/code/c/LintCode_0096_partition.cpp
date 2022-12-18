#include <iostream>

using namespace std;

// https://www.lintcode.com/problem/96

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};


ListNode* partition(ListNode* head, int x) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	ListNode* smallHead = NULL;
	ListNode* smallEnd = NULL;

	ListNode* bigHead = NULL;
	ListNode* bigEnd = NULL;

	ListNode* cur = head;
	ListNode* temp = NULL;

	while (cur != NULL) {
		temp = cur->next;
		if (cur->val < x) {
			if (smallHead == NULL) {
				smallHead = cur;
				smallEnd = cur;
			}
			else {
				smallEnd->next = cur;
				smallEnd = smallEnd->next;
			}
		}
		else {
			if (bigHead == NULL) {
				bigHead = cur;
				bigEnd = cur;
			}
			else {
				bigEnd->next = cur;
				bigEnd = bigEnd->next;
			}
		}
		cur->next = NULL;
		cur = temp;
	}

	if (smallEnd == NULL) {
		return bigHead;
	}
	else {
		if (bigHead != NULL) {
			smallEnd->next = bigHead;
		}
	}

	return smallHead;
}