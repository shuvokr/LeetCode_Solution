// Link : https://leetcode.com/problems/stone-game-ii

class Solution {
public:
    vector<int> pilesStack;
    int mamo[ 101 ][ 51 ];
    int stoneGameII(vector<int>& piles) {
        pilesStack = piles;
        int total = 0;
        for(int i = 0; i < piles.size(); i++) total += piles[i];
        memset(mamo, -1, sizeof mamo);
        return DP(0, 1, total);
    }
    int DP(int position, int M, int remainStones) {
        int &ret = mamo[position][M];
        if(ret != -1) return ret;
        
        ret = 0;
        int sum = 0;
        for(int i = 0; i < (M << 1); i++) {
            if(position + i >= pilesStack.size()) continue;
            sum += pilesStack[i + position];
            ret = max(ret, remainStones - DP(1 + i + position, min(max(M, i + 1), 50), remainStones - sum));
        }
        return ret;
    }
};
