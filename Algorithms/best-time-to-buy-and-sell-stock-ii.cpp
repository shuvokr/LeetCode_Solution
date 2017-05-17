// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/#/description
int mamo[ 100005 ][ 2 ], len;
class Solution {
public:
    vector<int> p;
    int maxProfit(vector<int>& prices) 
    {
        memset(mamo, -1, sizeof mamo);
        p = prices; len = p.size();
        return DP(0, 0);
    }
    int DP(int pos, int s)
    {
        if(pos >= len) return 0;
        int &ret = mamo[ pos ][ s ];
        if(ret != -1) return ret;
        int a = DP(pos + 1,  s);
        int b = 0;
        if(s) b = DP(pos + 1, 0) + p[ pos ];
        int c = 0;
        if(!s) c = DP(pos + 1, 1) - p[pos];
        return ret = max(a, max(b, c));
    }
};
