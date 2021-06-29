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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) {
            return nullptr;
        }
        
        int last = postorder.size() - 1;
        TreeNode* root = new TreeNode(postorder[last]);
        
        int i = 0;
        for (; i < inorder.size(); ++i) {
            if (inorder[i] == postorder[last]) {
                break;
            }
        }
        
        vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + i);
        vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());
        vector<int> rightPostorder(postorder.begin() + i, postorder.end() - 1);
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        
        return root;
    }
};
