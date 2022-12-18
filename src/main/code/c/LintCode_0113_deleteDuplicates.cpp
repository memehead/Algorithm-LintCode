#include <iostream>

using namespace std;

// https://www.lintcode.com/problem/113

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* deleteDuplicates_0113(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    ListNode* dummmy = new ListNode(1);
    dummmy->next = head;
    ListNode* newHead = dummmy;

    ListNode* pre = head;
    ListNode* cur = head->next;

    while (cur != NULL) {
        if (pre->val == cur->val) {
            cur = cur->next;
        }
        else {
            if (pre->next == cur) {
                newHead->next = pre;
                newHead = pre;
            }
            pre = cur;
            cur = cur->next;
        }
    }

    if (pre->next == NULL) {
        newHead->next = pre;
    }
    else {
        newHead->next = cur;
    }

    return dummmy->next;
}

//int main() {
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//	ListNode* node4 = new ListNode(3);
//	ListNode* node5 = new ListNode(4);
//	ListNode* node6 = new ListNode(4);
//	ListNode* node7 = new ListNode(5);
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = node6;
//	node6->next = node7;
//
//	ListNode* ans = deleteDuplicates_0113(node1);
//
//	return 0;
//}