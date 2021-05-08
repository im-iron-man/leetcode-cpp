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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        
        int val;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                val = l2->val;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                val = l1->val;
                l1 = l1->next;
            } else {
                if (l1->val < l2->val) {
                    val = l1->val;
                    l1 = l1->next;
                } else {
                    val = l2->val;
                    l2 = l2->next;
                }
            }
            
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        
        ListNode *root = dummy->next;
        delete dummy;
        return root;
    }
};
