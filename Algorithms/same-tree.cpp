// Link: https://leetcode.com/problems/same-tree/description/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        ret = true;
        solve(p, q);
        return ret;
    }
    void solve(TreeNode* p, TreeNode* q)
    {
        if(!ret) return;
        if(p == NULL && q == NULL) return;
        else if((p != NULL && q == NULL) || (p == NULL && q != NULL)) ret = false;
        else if(p->val == q->val)
        {
            solve(p->left, q->left);
            solve(p->right, q->right);
        }
        else ret = false;
    }
};
