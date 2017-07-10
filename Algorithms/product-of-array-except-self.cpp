// https://leetcode.com/problems/product-of-array-except-self/#/description
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int numsSize = nums.size(), i, backk[numsSize], frontt[numsSize];
        backk[numsSize - 1] = nums[numsSize - 1];
        frontt[0] = nums[0];
        for(i = 1; i < numsSize; i++)
        {
            frontt[i] = nums[i] * frontt[i - 1];
            backk[numsSize - i - 1] = nums[numsSize - i - 1] * backk[numsSize - i];
        }
        for(i = 0; i < numsSize; i++)
            nums[i] = i == 0 ? backk[1] : i == numsSize - 1 ? frontt[numsSize - 2] : frontt[i - 1] * backk[i + 1];
        return nums;
    }
};
