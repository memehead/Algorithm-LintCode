#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/1292

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* oddEvenList(ListNode* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return head;
	}

	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* flag = even;

	ListNode* ans = odd;
	while (even->next != NULL) {
		odd->next = even->next;
		odd = odd->next;
	
		even->next = odd->next;
		even = even->next;
	}

	odd->next = flag;

	return ans;
}