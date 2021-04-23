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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode();
        ListNode *temp = root;
        int r = 0;
        while (l1 != nullptr || l2 != nullptr || r != 0) {
            int a = l1 != nullptr ? l1->val : 0;
            int b = l2 != nullptr ? l2->val : 0;
            r += a + b;            
            temp->next = new ListNode(r % 10);
            temp = temp->next;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
            r /= 10;
        }
        ListNode *first = root;
        root = root->next;
        delete first;
        return root;
    }
};
