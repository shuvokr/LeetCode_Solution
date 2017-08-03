// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
class Solution {
public:
    int minDepth(TreeNode* root) {
        return root == NULL ? 0 : root->left == NULL ? 1 + minDepth(root->right) : root->right == NULL ? 1 + minDepth(root->left) : min(1 + minDepth(root->left), 1 + minDepth(root->right));
    }
};
