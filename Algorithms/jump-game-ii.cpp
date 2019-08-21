// Link : https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0, maxValue = 0, nowMax = 0;
        for(int i = 0, next; i < nums.size(); i++) {
            next = i + nums[i];
            if(i > nowMax) ret++, nowMax = maxValue;
            maxValue = maxValue < next ? next : maxValue;
        }
        return ret;
    }
};
