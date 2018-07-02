// Link: https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int ret;
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root);
        return ret;
    }
    int DFS(TreeNode* tree)
    {
        if(!tree) return 0;
        int a = DFS(tree->left), b = DFS(tree->right);
        ret = a + b > ret ? a + b : ret; a++, b++;
        return a > b ? a : b;
    }
};
