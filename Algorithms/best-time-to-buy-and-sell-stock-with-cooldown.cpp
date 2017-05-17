// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/#/description
int mamo[ 10005 ][ 3 ][ 2 ], len;
class Solution {
public:
    vector<int> p;
    int maxProfit(vector<int>& prices) 
    {
        memset(mamo, -1, sizeof mamo);
        p = prices; len = p.size();
        return DP(0, 0, 0);
    }
    int DP(int pos, int flag, int s)
    {
        if(pos >= len) return 0;
        int &ret = mamo[ pos ][ flag ][ s ];
        if(ret != -1) return ret;
        int a = DP(pos + 1, 1, s);
        int b = 0;
        if(s) b = DP(pos + 2, 2, 0) + p[ pos ];
        int c = 0;
        if(!s) c = DP(pos + 1, 0, 1) - p[pos];
        return ret = max(a, max(b, c));
    }
};
