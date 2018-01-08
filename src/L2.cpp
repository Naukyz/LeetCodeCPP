/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
const int null = 0;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(null) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *h = new ListNode(-1);
        ListNode *p = h;
        int carry = 0;
        while (l1 != null || l2 != null) {
            int a1 = l1 == null ? 0 : l1->val;
            int a2 = l2 == null ? 0 : l2->val;
            int sum = a1 + a2 + carry;
            p->next = new ListNode(sum % 10);
            p = p->next;
            carry = sum / 10;
            if (l1 != null) {
                l1 = l1->next;
            }
            if (l2 != null) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            p->next = new ListNode(1);
        }
        return h->next;
    }
};
