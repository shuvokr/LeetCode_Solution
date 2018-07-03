// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid;
        for(;high - low > 1;)
        {
            mid = (high + low) >> 1;
            if(nums[mid] > nums[ high ]) low = mid;
            else high = mid;
        }
        return nums[low] < nums[high] ? nums[low] : nums[high];
    }
};
