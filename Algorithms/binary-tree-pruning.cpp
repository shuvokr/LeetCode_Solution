// https://leetcode.com/problems/binary-tree-pruning/description/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        solve(root);
        return root;
    }
    void solve(TreeNode* &root)
    {
        if(!root) return;
        solve(root->left); solve(root->right);
        if(!root->val && !root->left && !root->right) root = NULL;
    }
};
