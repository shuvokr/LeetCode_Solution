// https://leetcode.com/problems/bitwise-and-of-numbers-range/#/description
int rangeBitwiseAnd(int m, int n) 
{
    if(!m) return 0;
    int a = log10(m)/log10(2);
    int b = log10(n)/log10(2);
    return a == b ? (1 << a) + rangeBitwiseAnd(m - (1 << a), n - (1 << a)) : 0;
}
