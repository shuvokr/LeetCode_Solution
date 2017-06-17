// https://leetcode.com/problems/jump-game/#/description
bool canJump(int* nums, int numsSize) 
{
    int i = 0, now = 0;
    for(;i < numsSize && i <= now && now + 1 < numsSize; i++)
        now = i + nums[i] > now ? i + nums[i] : now;
    return now + 1 >= numsSize;
}
