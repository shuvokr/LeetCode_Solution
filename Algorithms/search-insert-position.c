// https://leetcode.com/problems/search-insert-position/#/description
int searchInsert(int* nums, int numsSize, int target) 
{
    int left = 0, right = numsSize - 1, mid;
    while(right - left > 1)
    {
        mid = (right + left) >> 1;
        if(target > nums[ mid ]) left = mid;
        else right = mid;
    }
    
    if(target < nums[left] || target == nums[left]) return left;
    if(target == nums[right] || target < nums[right]) return right;
    if(target > nums[left] && target < nums[right]) return left + 1;
    return right + 1;
}
