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
    unordered_map<int, int> mp;
    vector<int> findMode(TreeNode* root) {
        mp.clear();
        treeTraverse(root);
        int mx = INT_MIN;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(mx < it->second) {
                mx = it->second;
            }
        }
        vector<int> ret;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(mx == it->second) {
                ret.push_back(it->first);
            }
        }
        return ret;
        
    }
    void treeTraverse(TreeNode* tree) {
        if(tree == NULL) return;
        mp[tree->val]++;
        treeTraverse(tree->left);
        treeTraverse(tree->right);
    }
};
