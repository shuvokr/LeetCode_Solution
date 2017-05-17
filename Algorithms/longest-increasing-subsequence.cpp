// https://leetcode.com/problems/longest-increasing-subsequence/#/description
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;
        int mamo[nums.size()]={0}, ret = 0;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
                if(nums[ j ] > nums[ i ])
                {
                    mamo[ j ] = max(mamo[ j ], 1 + mamo[i]);
                    ret = mamo[ j ] > ret ? mamo[ j ] : ret;
                }
        return ret + 1;
    }
};
