// https://leetcode.com/problems/missing-number/#/description
int missingNumber(int* nums, int numsSize) 
{
    int ret = numsSize;
    for(int i = 0; i < numsSize; i++)
    {
        ret ^= i;
        ret ^= nums[i];
    }
    return ret;
}
