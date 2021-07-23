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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* root = new ListNode(0, head);
        ListNode* temp1 = root;
        
        for (ListNode *temp2 = head; temp2 != nullptr; temp2 = temp2->next) {
            if (temp2->val != val) {
                temp1->next = temp2;
                temp1 = temp1->next;
            }
        }
        temp1->next = nullptr;
        
        ListNode* result = root->next;
        delete root;
        return result;
    }
};
