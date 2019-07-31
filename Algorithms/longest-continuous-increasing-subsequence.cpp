// Link : https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ret = 0, count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] > nums[i - 1]) count++, ret = ret < count ? count : ret;
            else count = 1;
        }
        return ret;
    }
};
