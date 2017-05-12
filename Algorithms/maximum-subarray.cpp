//Problem Description: https://leetcode.com/problems/maximum-subarray/#/description
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = -2147483648, sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ret = ret < sum ? sum : ret;
            sum = sum < 0 ? 0 : sum;
        }
        return ret;
    }
};
