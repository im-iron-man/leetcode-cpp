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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (true) {
            if (fast != nullptr) {
                fast = fast->next;
            } else {
                return false;
            }
            if (fast != nullptr) {
                fast = fast->next;
            } else {
                return false;
            }
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        
        return false;
    }
};
