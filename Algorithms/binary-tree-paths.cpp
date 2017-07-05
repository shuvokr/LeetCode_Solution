// https://leetcode.com/problems/binary-tree-paths/#/description
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
    template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
public:
    vector <string> ret;
    string str;
    vector<string> binaryTreePaths(TreeNode* root)
    {
        ret.clear(); str = "";
        if(root == NULL) return ret;
        solve(root);
        return ret;
    }
    void solve(TreeNode *bTree)
    {
        string num = toString(bTree->val);
        str += num;
        if(bTree->left == NULL && bTree->right == NULL)
        {
            ret.push_back(str);
            int cou = num.size();
            while( cou-- ) str.pop_back();
            return;
        }
        
        str += "->";
        if(bTree->left != NULL) solve(bTree->left);
        if(bTree->right != NULL) solve(bTree->right);
        
        int cou = 2 + num.size();
        while(cou--) str.pop_back();
    }
};
