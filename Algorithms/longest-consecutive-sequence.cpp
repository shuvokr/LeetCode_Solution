// https://leetcode.com/problems/longest-consecutive-sequence/description/
class Solution {
    const long long goPositive = (1LL << 32LL);
public:
    int longestConsecutive(vector<int>& nums) 
    {
        map<long long, bool> mp;
        int ret = 0, mxResult = 0;
        long long last = -1;
        for(int i = 0; i < nums.size(); i++) mp[ goPositive + nums[i] ] = true;
        for(map<long long, bool> :: iterator it = mp.begin(); it != mp.end(); it++)
        {
            if(last == -1)
            {
                ret = 1;
                last = it->first;
                mxResult = mxResult < ret ? ret : mxResult;
            }
            else if(last + 1 == it->first)
            {
                ret++;
                last++;
                mxResult = mxResult < ret ? ret : mxResult;
            }
            else
            {
                ret = 1;
                last = it->first;
                mxResult = mxResult < ret ? ret : mxResult;
            }
        }
        return mxResult;
    }
};
