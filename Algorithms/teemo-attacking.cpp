//Problem Description: https://leetcode.com/problems/teemo-attacking/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0, tmp = -1, len = timeSeries.size(), i = 0;
        for(;i < len; i++)
        {
            if(tmp < timeSeries[i]) ret += duration, tmp = timeSeries[i] + duration - 1;
            else
            {
                int rem = tmp - timeSeries[i] + 1;
                ret = ret + duration - rem;
                tmp = timeSeries[i] + duration - 1;
            }
        }
        return ret;
    }
};
