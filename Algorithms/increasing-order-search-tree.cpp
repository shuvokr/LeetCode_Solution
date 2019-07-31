// Link : https://leetcode.com/problems/increasing-order-search-tree

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
    vector<int> nums;
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        root = new TreeNode(nums[0]);
        TreeNode* tree = root;
        for(int i = 1; i < nums.size(); i++) {
            TreeNode* newOne = new TreeNode(nums[i]);
            tree->right = newOne;
            tree = newOne;
        }
        return root;
    }
    void solve(TreeNode* tree) {
        if(tree == NULL) return;
        solve(tree->left);
        nums.push_back(tree->val);
        solve(tree->right);
    }
};
