// Link: https://leetcode.com/problems/invert-binary-tree/description/

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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root) return NULL;
        TreeNode *left = invertTree(root->left), *right = invertTree(root->right), *resultTree = new TreeNode(root->val);
        resultTree->left = right; resultTree->right = left;
        return resultTree;
    }
};
