https://leetcode.com/problems/convert-bst-to-greater-tree/description/

class Solution {
public:
    int sumUp = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        convertBST(root->right);
        sumUp += root->val;
        root->val = sumUp;
        convertBST(root->left);
        return root;
    }
};
