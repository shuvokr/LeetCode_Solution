//Problem Description: https://leetcode.com/problems/target-sum
class Solution 
{
public:
    vector <int> value;
    int len, mamo[ 20 ][ 3210 ][ 3 ];
    int findTargetSumWays(vector<int>& nums, int S)
    {
        memset(mamo, -1, sizeof mamo);
        len = nums.size(); value = nums;
        if(S > 1000) return 0;
        else return DP(0, S + 1000, 0);
    }
    
    int DP(int pos, int val, int flag)
    {
        if(val == 1000 && pos == len) return 1;
        if(pos == len) return 0;
        int &ret = mamo[ pos ][ val ][ flag ];
        if(ret != -1) return ret;
        ret = 0;
        
        ret = DP(pos + 1, val + value[ pos ], 1) + DP(pos + 1, val - value[ pos ], 0);
        
        return ret;
    }
};
