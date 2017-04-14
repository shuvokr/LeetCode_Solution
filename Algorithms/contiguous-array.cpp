//Problem Description: https://leetcode.com/problems/contiguous-array
class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int len = nums.size(), ret = 0, mp[50005 << 1];
        memset(mp, -1, sizeof mp);
        mp[ 50001 ] = 0;
        for(int i = 0, cou = 50001; i < len; i++)
        {
            cou += nums[i] ? 1 : -1;
            if(mp[cou] == -1) mp[cou] = i + 1;
            else ret = ret < 1 + i - mp[cou] ? 1 + i - mp[cou] : ret;
        }
        return ret;
    }
};
