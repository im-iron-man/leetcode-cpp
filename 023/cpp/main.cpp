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

class BinaryHeap {
private:
    vector<ListNode *> v;
    
    int parent(int i) {
        return (i - 1) / 2;
    }
    
    int leftChild(int i) {
        return i * 2 + 1;
    }
    
    int rightChild(int i) {
        return i * 2 + 2;
    }
    
    void swap(int i, int j) {
        ListNode *n = v[i];
        v[i] = v[j];
        v[j] = n;
    }
    
    void up() {
        int i = v.size() - 1;
        int val = v[i]->val;
        while (i > 0) {
            int j = parent(i);
            if (v[j]->val < val) {
                break;
            }
            swap(i, j);
            i = j;
        }
    }
    
    void down() {
        int i = 0;
        int val = v[i]->val;
        while (true) {
            int j = i;
            int t = val;
            
            int j1 = leftChild(i);
            if (j1 < v.size() && v[j1]->val < t) {
                j = j1;
                t = v[j1]->val;
            }
            
            int j2 = rightChild(i);
            if (j2 < v.size() && v[j2]->val < t) {
                j = j2;
                t = v[j2]->val;
            }
            
            if (i == j) {
                break;
            }
            
            swap(i, j);
            i = j;
        }
    }

public:
    int size() {
        return v.size();
    }
    
    ListNode *min() {
        return v[0];
    }
    
    ListNode *deleteMin() {
        ListNode *n = min();
        swap(0, size() - 1);
        v.pop_back();
        if (size() > 0) {
            down();
        }
        return n;
    }
    
    void insert(ListNode *n) {
        v.push_back(n);
        up();
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        BinaryHeap bh;
        
        for (ListNode *n: lists) {
            if (n != nullptr) {
                bh.insert(n);
            }
        }
        
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        
        while (bh.size() > 0) {
            ListNode *n = bh.deleteMin();
            
            temp->next = new ListNode(n->val);
            temp = temp->next;
            
            n = n->next;
            if (n != nullptr) {
                bh.insert(n);
            }
        }
        
        ListNode *root = dummy->next;
        delete dummy;
        return root;
    }
};
