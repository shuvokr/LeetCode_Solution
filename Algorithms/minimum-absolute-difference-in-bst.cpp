//Problem Description: https://leetcode.com/problems/minimum-absolute-difference-in-bst
class Solution 
{
    public:
    int ret = 2147483647, val = -1;
    int getMinimumDifference(TreeNode* root) 
    {
        if (root->left != NULL) getMinimumDifference(root->left);
        if (val >= 0) ret = min(ret, root->val - val);
        val = root->val;
        if (root->right != NULL) getMinimumDifference(root->right);
    
        return ret;
    }
};
