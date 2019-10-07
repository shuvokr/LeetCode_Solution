class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int ret = 0, len = chips.size();
        for(auto p : chips) ret += (p % 2);
        ret = min(ret, len - ret);
        return ret;
        
    }
};


