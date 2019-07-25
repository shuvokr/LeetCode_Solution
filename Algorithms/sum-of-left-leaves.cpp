// Link: https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        int val = root->left == NULL || (root->left->left || root->left->right) ? 0 : root->left->val;
        return val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
