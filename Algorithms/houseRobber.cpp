//Problem Description: https://leetcode.com/problems/house-robber
class Solution 
{
public:
    int mamo[ 110 ][ 2 ], len;
    vector <int> money;
    
    int rob(vector<int>& nums)
    {
        memset(mamo, -1, sizeof mamo);
        money = nums; len = nums.size();
        return DP(0, 0);
    }
    
    int DP(int pos, int flag)
    {
        if(pos >= len) return 0;
        int &ret = mamo[ pos ][ flag ];
        if(ret != -1) return ret;
        ret = 0;
        ret = max(money[ pos ] + DP(pos + 2, 1), DP(pos + 1, 0));
        return ret;
    }
};
