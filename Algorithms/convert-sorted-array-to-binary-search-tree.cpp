// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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
    vector<int> array;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        array = nums;
        return solve(start, end);
    }
    TreeNode* solve(int start, int end)
    {
        if(start > end) return NULL;
        int mid = (start + end + 1) >> 1;
        TreeNode* tree = new TreeNode(array[ mid ]);
        tree->left = solve(start, mid - 1);
        tree->right = solve(mid + 1, end);
        return tree;
    }
};
