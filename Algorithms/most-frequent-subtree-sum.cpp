// Link: https://leetcode.com/problems/most-frequent-subtree-sum/description/

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
    map<int, int>mp;
    int maxFreq;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxFreq = 0; treeSum(root);
        vector<int> answer;
        for(map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++) if(it->second == maxFreq) answer.push_back(it->first);
        return answer;
    }
    int treeSum(TreeNode* tree)
    {
        if(!tree) return 0;
        tree->val += treeSum(tree->left) + treeSum(tree->right);
        mp[tree->val]++;
        maxFreq = mp[tree->val] > maxFreq ? mp[tree->val] : maxFreq;
        return tree->val;
    }
};
