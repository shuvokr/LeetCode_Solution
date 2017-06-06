// https://leetcode.com/problems/single-element-in-a-sorted-array/#/description
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int left = 0, right = nums.size() - 1, mid;
        while(left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (mid&1) 
            {
                if (nums[mid] == nums[mid-1]) left = mid + 1;
                else if (nums[mid] == nums[mid+1]) right = mid - 1;
            }
            else 
            {
                if (nums[mid] == nums[mid-1]) right = mid - 2;
                else if (nums[mid] == nums[mid+1]) left = mid + 2;
                else return nums[mid];
            }
        }
        return nums[ left ];
    }
};
