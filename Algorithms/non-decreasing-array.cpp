// Link: https://leetcode.com/problems/non-decreasing-array/description/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cou = 0, p, t;
        bool x = true;
        for(int i = 1, len = nums.size(); i < len; i++) 
            if(nums[i] < nums[i - 1]) p = nums[i], t = i, nums[i] = nums[i - 1], i = len;
        for(int i = 1, len = nums.size(); i < len; i++) 
            if(nums[i] < nums[i - 1]) x = false;
        if(x) return true;
        nums[t] = p;
        for(int i = 1, len = nums.size(); i < len; i++) 
            if(nums[i] < nums[i - 1]) p = nums[i], nums[i - 1] = nums[i], i = len;
        for(int i = 1, len = nums.size(); i < len; i++) 
            if(nums[i] < nums[i - 1]) return false;
        return true;
    }
};
