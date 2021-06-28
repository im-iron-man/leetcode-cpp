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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        int i = 0;
        for (; i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) {
                break;
            }
        }
        
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
        vector<int> rightPreorder(preorder.begin() + i + 1., preorder.end());
        vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        
        return root;
    }
};
