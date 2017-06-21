// https://leetcode.com/problems/integer-replacement/#/description
int integerReplacement(int n) 
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(n&1) 
    {
        int a = 2 + integerReplacement((n - 1) >> 1);
        int b = 2 + integerReplacement(((long long)n + 1ll) >> 1ll);
        a = a < b ? a : b;
        return a;
    }
    else return 1 + integerReplacement(n >> 1);
}
