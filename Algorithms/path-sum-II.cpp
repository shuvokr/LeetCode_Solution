// https://leetcode.com/problems/path-sum-II/#/description
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
    vector< vector<int> > ret;
    vector <int> lisT;
    int ind;
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        if(root == NULL) return ret;
        solve(root, sum);
        return ret;
    }
    void solve(TreeNode *bTree, int sum)
    {
        lisT.push_back(bTree->val);
        if(bTree->left == NULL && bTree->right == NULL)
        {
            if(sum == bTree->val) ret.push_back(lisT);
            lisT.pop_back();
            return;
        }
        
        if(bTree->left != NULL) solve(bTree->left, sum - bTree->val); 
        if(bTree->right != NULL) solve(bTree->right, sum - bTree->val);
        lisT.pop_back();
    }
};
