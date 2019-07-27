// Link : https://leetcode.com/problems/univalued-binary-tree/
// Tag : Simple Recursion

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
    bool ret = true;
    int check = -1;
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        if(check == -1) check = root->val;
        if(root->val != check) return false;
        return ret = ret & isUnivalTree(root->left) & isUnivalTree(root->right);
    }
};
