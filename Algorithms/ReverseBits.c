//Problem Description: https://leetcode.com/problems/reverse-bits
unsigned int reverseBits(unsigned int n) 
{
    unsigned int ret = 1;
    int ar[ 32 ];
    memset(ar, 0, sizeof ar);
    int i = 0, j;
    while(n)
    {
        ar[ i ] = (n&1);
        i++; n >>= 1;
    }
    for(j = 31; j > -1; j--)
    	ret += ar[ j ] ? ( 1 << (31 - j)) : 0;
    return ret - 1;
}
