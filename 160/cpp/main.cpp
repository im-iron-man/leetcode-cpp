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
        // check cycle
        ListNode *a = headA;
        while (a != nullptr) {
            ListNode *b = headB;
            while (b != nullptr) {
                if (a == b) {
                    return a;
                }
                b = b->next;
            }
            a = a->next;
        }
        return nullptr;
    }
};
