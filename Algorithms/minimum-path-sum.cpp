// https://leetcode.com/problems/minimum-path-sum/#/description
int mamo[ 1000 ][ 1000 ];
class Solution {
public:
    vector< vector<int> > v;
    int minPathSum(vector<vector<int>>& grid) {
        v = grid;
        memset(mamo, -1, sizeof mamo);
        return DP(v.size() - 1, v[0].size() - 1);
    }
    int DP(int a, int b)
    {
        if(a < 0 || b < 0) return 1000000000;
        if(!a && !b) return v[0][0];
        int &ret = mamo[ a ][ b ];
        if(ret != -1) return ret;
        ret = 2147483647;
        ret = min(ret, v[ a ][ b ] + DP(a - 1, b));
        ret = min(ret, v[ a ][ b ] + DP(a, b - 1));
        return ret;
    }
};
