//Problem Description: https://leetcode.com/problems/number-of-1-bits
int hammingWeight(unsigned int n) 
{
    int ret = 0;
    while(n)
    {
        if(n&1) ret++;
        n >>= 1;
    }
    return ret;
}
