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
class Attr {
public:
    int height;
    bool isBalanced;
    Attr(int height, bool isBalanced) : height(height), isBalanced(isBalanced) {}
};

class Solution {
public:
    Attr getHeightAndIsBalanced(TreeNode* root) {
        if (root == nullptr) {
            return Attr(0, true);
        }
        
        Attr left = getHeightAndIsBalanced(root->left);
        if (!left.isBalanced) {
            return Attr(0, false);
        }
        Attr right = getHeightAndIsBalanced(root->right);
        if (!right.isBalanced) {
            return Attr(0, false);
        }
        
        if (abs(left.height - right.height) <= 1) {
            return Attr(max(left.height, right.height) + 1, true);
        } else {
            return Attr(0, false);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        return getHeightAndIsBalanced(root).isBalanced;
    }
};
