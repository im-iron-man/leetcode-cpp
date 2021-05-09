/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *a = dummy;
        
        while (true) {
            ListNode *b = a->next;
            if (b == nullptr) {
                break;
            }
            ListNode *c = b->next;
            if (c == nullptr) {
                break;
            }
            ListNode *d = c->next;
            
            a->next = c;
            b->next = d;
            c->next = b;
            
            a = b;
        }
        
        ListNode *head0 = dummy->next;
        delete dummy;
        return head0;
    }
};
