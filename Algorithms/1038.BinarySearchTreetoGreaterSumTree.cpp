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
    int total = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return root;
        
        bstToGst(root->right);
        total += root->val;
        root->val = total;
        bstToGst(root->left);
        
        return root;
    }
};
