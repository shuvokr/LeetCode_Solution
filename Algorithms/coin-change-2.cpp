// https://leetcode.com/problems/coin-change-2/#/description
vector<int> coin;
int mamo[5005][505];
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        coin = coins;
        memset(mamo, -1, sizeof mamo);
        return DP(amount, coin.size() - 1);
    }
    int DP(int taka, int pos)
    {
        if(taka == 0) return 1;
        if(pos == -1 || taka < 0) return 0;
        int &ret = mamo[taka][pos];
        if(ret != -1) return ret;
        ret = 0;
        return ret = ret + DP(taka - coin[ pos ], pos) + DP(taka, pos - 1);
    }
};
