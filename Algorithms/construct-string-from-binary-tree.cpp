// Links : https://leetcode.com/problems/construct-string-from-binary-tree

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
    string result;
    string tree2str(TreeNode* t) {
        solve(t);
        return result;
    }
    void solve(TreeNode* tree) {
        if(tree == NULL) return;
        char ch = abs(tree->val) + 48;
        ostringstream value;
        value << tree->val;
        result += value.str(); 
        
        result += "(";
        solve(tree->left);
        if(result[ result.size() - 1 ] == '(' && tree->right == NULL) result.pop_back();
        else result += ")";
        
        result += "(";
        solve(tree->right);
        if(result[ result.size() - 1 ] == '(') result.pop_back();
        else result += ")";
    }
};
