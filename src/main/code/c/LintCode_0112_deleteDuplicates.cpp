#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/112

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* deleteDuplicates_0112(ListNode* head) {
	if (head == NULL) {
		return head;
	}

	ListNode* pre = head;
	ListNode* cur = head->next;

	while (cur != NULL) {
		if (cur->val != pre->val) {
			pre->next = cur;
			pre = cur;
		}
		cur = cur->next;
	}
	pre->next = cur;
	
	return head;
}