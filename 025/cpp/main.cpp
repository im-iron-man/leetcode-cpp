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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *a = dummy;
        
        while (true) {
            ListNode *t;
            
            t = a;
            vector<ListNode *> v;
            for (int i = 0; i < k; i++) {
                t = t->next;
                if (t == nullptr) {
                    goto END;
                }
                v.push_back(t);
            }
            
            a->next = v[v.size() - 1];
            v[0]->next = v[v.size() - 1]->next;
            for (int i = 1; i < k; i++) {
                v[i]->next = v[i - 1];
            }
            
            a = v[0];
        }
        
    END:
        ListNode *head0 = dummy->next;
        delete dummy;
        return head0;
    }
};
