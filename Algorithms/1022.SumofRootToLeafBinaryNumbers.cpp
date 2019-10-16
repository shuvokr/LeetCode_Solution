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
    bool mamo[64];
    int p = 0;
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) {
            mamo[p++] = root->val;
            int ret = 0;
            for(int i = 0; i < p; i++) {
                if(mamo[i])
                ret += (1 << (p - (i + 1)));
            }
            p--;
            return ret;
        }
        
        mamo[p++] = root->val;
        int a = sumRootToLeaf(root->left);
        int b = sumRootToLeaf(root->right);
        p--;
        return a + b;
    }
};
