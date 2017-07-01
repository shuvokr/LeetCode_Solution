// https://leetcode.com/problems/number-complement/#/description
int findComplement(int num) 
{
    int ret = 0, i, len = log10(num)/log10(2); len++;
    for(i = 0; i < len; i++)
        ret = !(num & (1<<i)) ? ret + (1 << i) : ret;
    return ret;
}
