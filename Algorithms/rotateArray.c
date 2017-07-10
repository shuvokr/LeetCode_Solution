// https://leetcode.com/problems/rotate-array/#/solutions
void rotate(int nums[], int numsSize, int k) 
{
    k = k - numsSize * (k / numsSize);
    int a = 0, b = numsSize - 1;
    while(a < b) nums[a] += nums[b], nums[b] = nums[a] - nums[b], nums[a] -= nums[b], a++, b--; a = 0; b = k - 1;
    while(a < b) nums[a] += nums[b], nums[b] = nums[a] - nums[b], nums[a] -= nums[b], a++, b--; a = k; b = numsSize - 1;
    while(a < b) nums[a] += nums[b], nums[b] = nums[a] - nums[b], nums[a] -= nums[b], a++, b--;
}
