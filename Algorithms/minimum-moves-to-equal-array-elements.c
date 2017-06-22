// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/#/description
int minMoves(int* nums, int numsSize) {
    int ret = 0, min = 2147483647, i;
    for(i = 0; i < numsSize; i++)
        min = min > nums[i] ? nums[i] : min;
    for(i = 0; i < numsSize; i++)
        ret += nums[i]-min;
    return ret;
}
