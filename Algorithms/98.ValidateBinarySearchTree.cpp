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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return isValidBSTSolver(root, LLONG_MIN, LLONG_MAX);
    }
    bool isValidBSTSolver(TreeNode* root, long long minValue, long long maxValue) {
        if(root == NULL) return true;
        if(minValue >= root->val || maxValue <= root->val) return false;
        
        return isValidBSTSolver(root->left, minValue, root->val) && 
            isValidBSTSolver(root->right, root->val, maxValue);
    }
};
