#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/36
class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || m == n) {
        return head;
    }
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* mIndexNode = dummy;
    ListNode* mIndexPreNode;

    while (m != 0) {
        mIndexPreNode = mIndexNode;
        mIndexNode = mIndexNode->next;
        m--;
    }

    ListNode* nIndexNode = dummy;
    ListNode* nIndexNextNode;

    while (n != 0) {
        nIndexNode = nIndexNode->next;
        n--;
    }
    nIndexNextNode = nIndexNode->next;

    ListNode* cur = mIndexNode;
    ListNode* pre = NULL;
    ListNode* temp;

    while (cur != nIndexNextNode) {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    mIndexPreNode->next = pre;
    mIndexNode->next = nIndexNextNode;

    return dummy->next;
}