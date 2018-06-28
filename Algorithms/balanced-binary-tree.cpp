// Link: https://leetcode.com/problems/balanced-binary-tree/description/

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
    bool answer;
    bool isBalanced(TreeNode* root) {
       if(root == NULL) return true;
        answer = true;
        solve(root);
        return answer;
    }
    int solve(TreeNode* root)
    {
        if(!answer || root == NULL) return 0;
        int leftDepth = 1 + solve(root->left);
        int rightDepth = 1 + solve(root->right);
        answer = abs(leftDepth - rightDepth) > 1 ? false : answer;
        return leftDepth > rightDepth ? leftDepth : rightDepth;
    }
};
