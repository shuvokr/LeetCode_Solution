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
    vector<int> ret;
    vector<int> largestValues(TreeNode* root) {
        ret.clear();
        if(root == NULL) return ret;
        solve(root, 0);
        return ret;
    }
    void solve(TreeNode* tree, int p) {
        if(tree == NULL) return;
        if(ret.size() <= p) ret.push_back(tree->val);
        else ret[p] = max(ret[p], tree->val);
        
        solve(tree->left, p + 1);
        solve(tree->right, p + 1);
    }
};
