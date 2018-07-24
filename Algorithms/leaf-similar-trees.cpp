https://leetcode.com/problems/leaf-similar-trees/description/

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
    vector<int> a, b;
    bool ck;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        ck = false;
        solve(root1); 
        ck = true;
        solve(root2);
        return a == b;
    }
    void solve(TreeNode* tree)
    {
        if(!tree) return;
        if(tree->left == NULL && tree->right == NULL)
        {
            if(ck) b.push_back(tree->val);
            else a.push_back(tree->val);
            return;
        }
        solve(tree->left);
        solve(tree->right);
    }
};
