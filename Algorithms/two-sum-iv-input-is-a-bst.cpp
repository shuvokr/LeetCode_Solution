// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

class Solution {
public:
    map<int, bool> mp;
    int K;
    bool findTarget(TreeNode* root, int k) {
        mp.clear(); K = k;
        return solve(root);
    }
    bool solve(TreeNode* tree)
    {
        if(!tree) return false;
        if(mp.find(K - tree->val) != mp.end()) return true;
        mp[tree->val] = true;
        return solve(tree->left) || solve(tree->right);
    }
};
