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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        
        int i = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[i]);
        
        vector<int> a(nums.begin(), nums.begin() + i);
        vector<int> b(nums.begin() + i + 1, nums.end());
        root->left = sortedArrayToBST(a);
        root->right = sortedArrayToBST(b);
        return root;
    }
};
