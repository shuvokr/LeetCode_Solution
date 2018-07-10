// Link: https://leetcode.com/problems/maximum-binary-tree/description/

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
    vector<int> list;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        list = nums;
        TreeNode* tree;
        return solve(tree, 0, nums.size() - 1);
    }
    TreeNode* solve(TreeNode* tree, int l, int r)
    {
        if(l > r) return NULL;
        int mx = list[l], mid = l;
        for(int i = r; i > l; i--)
            mid = mx < list[i] ? i : mid, mx = mx < list[i] ? list[i] : mx;
        tree = new TreeNode(list[ mid ]);
        tree->left = solve(tree->left, l, mid - 1);
        tree->right = solve(tree->right, mid + 1, r);
        return tree;
    }
};
