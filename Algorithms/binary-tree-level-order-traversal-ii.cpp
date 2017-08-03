// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
class Solution {
    vector<vector<int>> ret;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        solve(root, 0);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void solve(TreeNode* root, int level)
    {
        if(root == NULL) return;
        if(ret.size() < level + 1) ret.resize(level + 1);
        ret[level].push_back(root->val);
        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
};
