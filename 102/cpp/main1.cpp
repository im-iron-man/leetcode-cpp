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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        vector<vector<int>> r;
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            TreeNode* a = p.first;
            int b = p.second;
            if (b >= r.size()) {
                r.push_back({});
            }
            r[b].push_back(a->val);
            if (a->left != nullptr) {
                q.push(make_pair(a->left, b + 1));
            }
            if (a->right != nullptr) {
                q.push(make_pair(a->right, b + 1));
            }
        }
        
        return r;
    }
};
