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
    void levelOrder(TreeNode* root, vector<vector<int>> &result, int i) {
        if (root == nullptr) {
            return;
        }

        if (i >= result.size()) {
            result.push_back({});
        }
        
        result[i].push_back(root->val);
        
        levelOrder(root->left, result, i + 1);
        levelOrder(root->right, result, i + 1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(root, result, 0);
        return result;
    }
};
