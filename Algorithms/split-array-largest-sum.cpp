// https://leetcode.com/problems/split-array-largest-sum/#/description
class Solution {
public:
    int len, sumNums[1002], mamo[1005][55];
    int splitArray(vector<int>& nums, int m) {
        len = nums.size();
        sumNums[0] = 0;
        memset(mamo, -1, sizeof mamo);
        for(int i = 1; i <= len; i++)
            sumNums[i] = sumNums[i - 1] + nums[i - 1];
        
        return DP(0, m);
    }
    int DP(int pos, int m)
    {
        if(m == 0 && pos == len) return -2147483647;
        if(m == 0 || pos == len) return 2147483647;
        int &ret = mamo[ pos ][ m ];
        if(ret != -1) return ret;
        ret = 2147483647;
        for(int i = 1; i + pos <= len; i++)
            ret = min(ret, max(sumNums[pos + i] - sumNums[pos], DP(pos + i, m - 1)));
        return ret;
    }
};
