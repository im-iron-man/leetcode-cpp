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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            return {{targetSum}};
        }
        targetSum -= root->val;
        vector<vector<int>> left = pathSum(root->left, targetSum);
        vector<vector<int>> right = pathSum(root->right, targetSum);
        vector<vector<int>> result;
        for (vector<int>& t: left) {
            t.insert(t.begin(), root->val);
            result.push_back(t);
        }
        for (vector<int>& t: right) {
            t.insert(t.begin(), root->val);
            result.push_back(t);
        }
        return result;
    }
};
