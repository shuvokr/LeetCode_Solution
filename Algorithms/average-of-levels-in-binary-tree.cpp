// https://leetcode.com/problems/average-of-levels-in-binary-tree/discuss/
class Solution {
    struct data
    {
        double sum, cou;
    }ret[ 10001 ];
    int len;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        len = 0;
        solve(root, 0);
        vector<double> v;
        for(int i = 0; i < len; i++)
        {
            if(ret[i].cou) v.push_back( ret[i].sum / ret[i].cou );
            else v.push_back( 0 );
        }
        return v;
    }
    void solve(TreeNode* root, int level)
    {
        if(root == NULL) return;
        len = level + 1 > len ? level + 1 : len;
        ret[level].sum += root->val;
        ret[level].cou++;
        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
};
