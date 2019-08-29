// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double total = 0.0, ret = 0.0;
        for(int i = 0; i < k; i++)
            total = total + nums[i];
        ret = total / (double)k;
        for(int i = k; i < nums.size(); i++) {
            total = total - nums[i - k];
            total = total + nums[i];
            double tmp = total / (double)k;
            ret = max(ret, tmp);
        }
        return ret;
    }
};
