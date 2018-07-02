// Link: https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> answer;
    int mxd;
    vector<int> rightSideView(TreeNode* root) {
        mxd = -1;
        solve(root, 0);
        return answer;
    }
    void solve(TreeNode* tree, int depth)
    {
        if(!tree) return;
        if(mxd < depth) answer.push_back(tree->val);
        mxd = depth < mxd ? mxd : depth;
        solve(tree->right, depth + 1);
        solve(tree->left, depth + 1);
    }
};
