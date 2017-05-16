//Problem Description: https://leetcode.com/problems/integer-break/#/description
int mamo[ 60 ][ 60 ];
class Solution {
public:
    int integerBreak(int n) {
        memset(mamo, -1, sizeof mamo);
        return DP(n, 0);
    }
    int DP(int pos, int take)
    {
        if(!pos) return 1;
        int &ret = mamo[ pos ][ take ];
        if(ret != -1) return ret;
        ret = 0;
        int limit = take == 0 ? pos : pos + 1;
        for(int i = 1; i < limit; i++)
            ret = max(ret, i * DP(pos - i, i));
        return ret;
    }
};
