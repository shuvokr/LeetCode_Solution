// Link: https://leetcode.com/problems/subtree-of-another-tree/description/

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        return solve(s, t, false) || solve(s, t, true);
    }
    bool solve(TreeNode* s, TreeNode* t, bool mark)
    {
        if(mark && !t && !s) return true;
        if(!t || !s) return false;
        if(mark && s->val != t->val) return false;
        
        if(mark) return solve(s->left, t->left, true) && solve(s->right, t->right, true);
        else return solve(s, t, true) || solve(s->left, t, false) || solve(s->right, t, false);
    }
};
