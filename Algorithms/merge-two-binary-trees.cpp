// Link: https://leetcode.com/problems/merge-two-binary-trees/description/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        solve(t1, t2);
        return t1;
    }
    void solve(TreeNode* &t1, TreeNode* t2)
    {
        if(!t2) return;
        if(!t1) t1 = new TreeNode(t2->val);
        else t1->val += t2->val;
        solve(t1->left, t2->left);
        solve(t1->right, t2->right);
    }
};
