// Link: https://leetcode.com/problems/symmetric-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return DFS(root->left, root->right);
    }
    bool DFS(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
        return DFS(left->left, right->right) && DFS(left->right, right->left);
    }
};
