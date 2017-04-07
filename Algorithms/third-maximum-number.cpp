//Problem Description: https://leetcode.com/problems/third-maximum-number
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int sk;
        long long mx = -11111111111, len = nums.size(), mxx = -11111111111, ret = -11111111111;
        for(int i = 0; i < len; i++) mx = nums[i] < mx ? mx : nums[i];
        for(int i = 0; i < len; i++) mxx = nums[i] > mxx && nums[i] != mx ? nums[i] : mxx;
        for(int i = 0; i < len; i++) ret = nums[i] > ret && nums[i] != mx && nums[i] != mxx ? nums[i] : ret;
        sk = ret == -11111111111 ? mx : ret;
        return sk;
    }
};
