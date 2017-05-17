//Problem Description: https://leetcode.com/problems/coin-change/#/description
int mamo[ 1005 ][ 10005 ];
class Solution {
public:
    vector <int> c;
    bool flag;
    int coinChange(vector<int>& coins, int amount) {
        memset(mamo, -1, sizeof mamo);
        c = coins; flag = true;
        int ret = DP(coins.size() - 1, amount);
        return flag ? -1 : ret;
    }
    int DP(int pos, int taka)
    {
        if(taka == 0) 
        {
            flag = false;
            return 0;
        }
        if(pos < 0 || taka < 0) return 1000000000;
        int &ret = mamo[ pos ][ taka ];
        if(ret != -1) return ret;
        ret = 1000000000;
        ret = min(ret, DP(pos - 1, taka));
        ret = min(ret, 1 + DP(c.size() - 1, taka - c[ pos ]));
        return ret;
    }
};
