//Problem Description: https://leetcode.com/problems/single-number
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[ 0 ];
        else
        {
            sort(nums.begin(), nums.end());
            nums.push_back(-123321123);
            int len = nums.size();
            for(int i = 0; i < len; i += 2)
                if(nums[i] != nums[i + 1]) return nums[i];
        }
    }
};
