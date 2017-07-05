// https://leetcode.com/problems/path-sum-III/#/description
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
    int save;
    int pathSum(TreeNode* root, int sum)
    {
        save = sum;
        return solve(root, sum, true);
    }
    int solve(TreeNode* root, int sum, bool flag)
    {
        if(root == NULL) return 0;
        int ret = (sum == root->val);
        if(flag) ret += solve(root->left, save, true);
        ret += solve(root->left, sum - root->val, false);
        if(flag) ret += solve(root->right, save, true);
        ret += solve(root->right, sum - root->val, false);
        return ret;
    }
};
