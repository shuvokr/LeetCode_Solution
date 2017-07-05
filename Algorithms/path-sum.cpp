// https://leetcode.com/problems/path-sum/#/description
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
    bool ret;
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(root == NULL)
            return false;
        ret = false;
        solve(root, sum);
        return ret;
    }
    void solve(TreeNode *bTree, int sum)
    {
        if(ret) return;
        if(bTree->left == NULL && bTree->right == NULL)
        {
            if(bTree->val == sum) ret = true;
            return;
        }
        
        if(bTree->left != NULL) solve(bTree->left, sum - bTree->val);
        if(bTree->right != NULL) solve(bTree->right, sum - bTree->val);
    }
};
