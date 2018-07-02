// Link: https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int p, fl = -1, sl = -1, len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(nums[i] > fl)
            {
                sl = fl;
                fl = nums[i];
                p = i;
            }
            else sl = sl < nums[i] ? nums[i] : sl;
        }
        return sl << 1 <= fl ? p : -1;
    }
};
