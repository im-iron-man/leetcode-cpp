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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (true) {
            if (fast != nullptr) {
                fast = fast->next;
            } else {
                return nullptr;
            }
            if (fast != nullptr) {
                fast = fast->next;
            } else {
                return nullptr;
            }
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        
        int n = 0;
        do {
            n++;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        
        slow = head;
        fast = head;
        for (int i = 0; i < n; fast = fast->next, i++);
        
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
            
        }
        return slow;
    }
};
