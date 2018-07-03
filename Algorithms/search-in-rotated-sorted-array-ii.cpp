// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        int low = 0, high = nums.size() - 1, mid;
        if(low > high) return false;
        for(;high - low > 1;)
        {
            if(nums[low] == target) return true;
            if(nums[high] == target) return true;
            mid = (high + low) >> 1;
            if(nums[mid] == target) return true;
            if((nums[mid] < target && nums[ high ] > target) ||
               (nums[mid] > target && nums[ high ] > target && nums[mid] > nums[high]) || 
               (nums[mid] < target && nums[ high ] < target && nums[mid] > nums[high])) low = mid;
            else high = mid;
        }
        return (nums[low] == target) || (target == nums[high]);
    }
};
