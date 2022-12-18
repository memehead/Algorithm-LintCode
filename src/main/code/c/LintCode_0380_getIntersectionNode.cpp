#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/380

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}
	int N = 0;

	ListNode* p1 = headA;
	ListNode* aEnd = NULL;
	while (p1 != NULL) {
		N++;
		aEnd = p1;
		p1 = p1->next;
	}

	ListNode* p2 = headB;
	ListNode* bEnd = NULL;
	while (p2 != NULL) {
		N--;
		bEnd = p2;
		p2 = p2->next;
	}

	if (aEnd != bEnd) {
		return NULL;
	}

	ListNode* longList = N > 0 ? headA : headB;
	ListNode* shortList = longList == headA ? headB : headA;

	N = abs(N);
	while (N > 0) {
		longList = longList->next;
		N--;
	}

	while (longList != shortList) {
		longList = longList->next;
		shortList = shortList->next;
	}

	return shortList;
}
