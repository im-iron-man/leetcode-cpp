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
        ListNode* temp = head;
        ListNode* node = head;
        while (temp != nullptr) {
            if (temp->val != node->val) {
                node->next = temp;
                node = temp;
            }
            temp = temp->next;
        }
        if (head != nullptr) {
            node->next = nullptr;
        }
        return head;
    }
};
