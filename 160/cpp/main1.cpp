/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *b1 = headA;
        ListNode *b2 = headB;
        while (b1 != b2) {
            b1 = b1 == nullptr ? headB : b1->next;
            b2 = b2 == nullptr ? headA : b2->next;
        }
        return b2 == nullptr ? nullptr : b1;
    }
};
