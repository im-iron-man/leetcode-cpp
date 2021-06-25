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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = new ListNode(-200, head);
        ListNode* node = root;
        ListNode* temp1 = root;
        ListNode* temp2 = head;
        bool ok = false;

        while (temp2 != nullptr) {
            if (temp2->val != temp1->val) {
                if (ok) {
                    node->next = temp1;
                    node = temp1;
                }
                temp1 = temp2;
                ok = true;
            } else {
                ok = false;
            }
            temp2 = temp2->next;
        }        
        node->next = ok ? temp1 : nullptr;

        head = root->next;
        delete root;
        return head;
    }
};
