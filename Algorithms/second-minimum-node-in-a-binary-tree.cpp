// Link : https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    long long firstMinimum, secondMinimum;
    int findSecondMinimumValue(TreeNode* root) {
        firstMinimum = 2147483648;
        secondMinimum = firstMinimum;
        solve(root);
        if(firstMinimum == secondMinimum || secondMinimum == 2147483648) return -1;
        else return (int)secondMinimum;
    }
    void solve(TreeNode* tree) {
        if(tree == NULL) return;
        firstMinimum = firstMinimum < tree->val ? firstMinimum : tree->val;
        secondMinimum = tree->val > firstMinimum && tree->val < secondMinimum ? tree->val : secondMinimum;
        solve(tree->left);
        solve(tree->right);
    }
};
