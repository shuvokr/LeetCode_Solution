// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == NULL ? 0 : root->left == NULL ? 1 + maxDepth(root->right) : root->right == NULL ? 1 + maxDepth(root->left) : max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};
