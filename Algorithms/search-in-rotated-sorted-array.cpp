// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        if(low > high) return -1;
        for(;high - low > 1;)
        {
            if(nums[low] == target) return low;
            if(nums[high] == target) return high;
            mid = (high + low) >> 1;
            if(nums[mid] == target) return mid;
            if((nums[mid] < target && nums[ high ] > target) ||
               (nums[mid] > target && nums[ high ] > target && nums[mid] > nums[high]) || 
               (nums[mid] < target && nums[ high ] < target && nums[mid] > nums[high])) low = mid;
            else high = mid;
        }
        return nums[low] == target ? low : target == nums[high] ? high : -1;
    }
};
