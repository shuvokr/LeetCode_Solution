// https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size() + 1, mamo[ 1010 ]; mamo[0] = mamo[1] = 0;
        for(int i = 2, a, b; i < len; i++)
        {
            a = mamo[i-2] + cost[i-2];
            b = mamo[i-1] + cost[i-1];
            mamo[i] = a < b ? a : b;
        }
        return mamo[len - 1];
    }
};
