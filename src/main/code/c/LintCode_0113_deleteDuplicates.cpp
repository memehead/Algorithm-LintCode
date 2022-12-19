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
