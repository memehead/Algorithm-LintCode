#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/223

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

bool isPalindrome(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}
	if (head->next->next == NULL) {
		return head->val == head->next->val;
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

	ListNode* left = head;
	ListNode* right = pre;

	bool flag = true;
	while (left != NULL && right != NULL) {
		if (left->val == right->val) {
			left = left->next;
			right = right->next;
		}
		else {
			flag = false;
			break;
		}
	}

	// 在把右半部分链表逆序回去
	temp = NULL;
	cur = pre;
	pre = NULL;

	while (cur != NULL) {
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}

	return flag;
}