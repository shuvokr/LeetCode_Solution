// Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    vector<int> v;
    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        sort(v.begin(), v.end());
        return v[k - 1];
    }
    void solve(TreeNode *root) {
        if(root == NULL) return;
        v.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
};
