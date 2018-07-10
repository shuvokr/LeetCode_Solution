//Link: https://leetcode.com/problems/longest-univalue-path/description/

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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        return max(ans, solve(root, true));
    }
    int solve(TreeNode* tree, bool ck)
    {
        if(!tree) return 0;
        int a = 0, b = 0, c = 0, d = 0;
        if(tree->left && tree->left->val == tree->val) a = 1 + solve(tree->left, false);
        if(ck) c = solve(tree->left, true);
        if(tree->right && tree->right->val == tree->val) b = 1 + solve(tree->right, false);
        if(ck) d = solve(tree->right, true);
        ans = max(ans, a+b);
        a = a < b ? b : a;
        a = a < c ? c : a;
        return max(a, d);
    }
};
