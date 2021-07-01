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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        TreeNode* r = new TreeNode();
        TreeNode* t = r;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* n = s.top();
            s.pop();
            t->right = new TreeNode(n->val);
            t = t->right;
            if (n->right != nullptr) {
                s.push(n->right);
            }
            if (n->left != nullptr) {
                s.push(n->left);
            }
        }
        *root = *(r->right);
        delete r;
    }
};
