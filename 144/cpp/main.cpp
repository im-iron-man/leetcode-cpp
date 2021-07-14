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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        vector<int> result = {root->val};
        vector<int> result1 = preorderTraversal(root->left);
        result.insert(result.end(), result1.begin(), result1.end());
        vector<int> result2 = preorderTraversal(root->right);
        result.insert(result.end(), result2.begin(), result2.end());
        return result;
    }
};
