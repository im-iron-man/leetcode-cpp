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
    void levelOrderBottom(TreeNode* root, vector<vector<int>>& result, int i) {
        if (root == nullptr) {
            return;
        }
        
        if (i >= result.size()) {
            result.insert(result.begin(), vector<int>{});
        }
        
        result[result.size() - 1 - i].push_back(root->val);
        levelOrderBottom(root->left, result, i + 1);
        levelOrderBottom(root->right, result, i + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {        
        vector<vector<int>> result;
        levelOrderBottom(root, result, 0);
        return result;
    }
};
