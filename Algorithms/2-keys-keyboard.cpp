//https://leetcode.com/problems/2-keys-keyboard/description

class Solution {
    int mamo[1001][1001];
    int targetN;
public:
    int minSteps(int n) {
        targetN = n;
        return DP(1, 0);
    }
    int DP(int nowN, int last)
    {
        if(nowN == targetN) return 0;
        if(nowN > targetN) return 1001;
        int &ret = mamo[nowN][last];
        if(ret) return ret;
        
        return ret = 1 + min(1 + DP(nowN << 1, nowN), last ? DP(nowN + last, last) : 1001);
    }
};
