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
class compare {
public:
    bool operator() (const ListNode *lhs, const ListNode *rhs) const {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        
        for (ListNode *n: lists) {
            if (n != nullptr) {
                pq.push(n);
            }
        }
        
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        
        while (!pq.empty()) {
            ListNode *n = pq.top();
            pq.pop();
            
            temp->next = new ListNode(n->val);
            temp = temp->next;
            
            n = n->next;
            if (n != nullptr) {
                pq.push(n);
            }
        }
        
        ListNode *root = dummy->next;
        delete dummy;
        return root;
    }
};
