//Problem Description: https://leetcode.com/problems/max-consecutive-ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0, cou = 0, len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(nums[ i ]) cou++;
            else
            {
                ret = ret < cou ? cou : ret;
                cou = 0;
            }
        }
        ret = ret < cou ? cou : ret;
        return ret;
    }
};
