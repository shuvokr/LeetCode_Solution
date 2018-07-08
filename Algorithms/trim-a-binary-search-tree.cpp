// Link: https://leetcode.com/problems/trim-a-binary-search-tree/description/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return root;
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        if(root->val > R) return root->left;
        if(root->val < L) return root->right;
        return root;
    }
};
