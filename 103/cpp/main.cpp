/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        int i = 0;
        vector<TreeNode*> next;
        next.push_back(root);
        vector<TreeNode*> next0;
        vector<vector<int>> result;
        while (!next.empty()) {
            result.push_back({});
            if (i % 2 == 0) {
                for (vector<TreeNode*>::iterator it = next.begin(); it != next.end(); ++it) {
                    result[i].push_back((*it)->val);
                }
            } else {
                for (vector<TreeNode*>::reverse_iterator  it = next.rbegin(); it != next.rend(); ++it) {
                    result[i].push_back((*it)->val);   
                }
            }
            for (vector<TreeNode*>::iterator it = next.begin(); it != next.end(); ++it) {
                if ((*it)->left != nullptr) {
                    next0.push_back((*it)->left);
                }
                if ((*it)->right != nullptr) {
                    next0.push_back((*it)->right);
                }
            }
            next.clear();
            next = next0;
            next0.clear();
            i++;
        }
        
        return result;
    }
};
