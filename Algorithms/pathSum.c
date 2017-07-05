//https://leetcode.com/problems/path-sum/#/description
bool hasPathSum(struct TreeNode* root, int sum) 
{
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) return sum == root->val ? true : false;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
