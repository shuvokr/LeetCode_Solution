// https://leetcode.com/problems/range-sum-of-bst

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL) return 0;
        return rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R) + (root->val >= L && root->val <= R ? root->val : 0);
    }
};
