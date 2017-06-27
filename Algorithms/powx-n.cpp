// https://leetcode.com/problems/powx-n/#/description
class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n < 0) return 1.0/pPow(x, (long)(-1)*n);
        return pPow(x, n);
    }
    double pPow(double x, long n)
    {
        if(!n) return 1.0;
        if(n&1) return x*pPow(x, n-1);
        else
        {
            double tmp = pPow(x, n>>1);
            return tmp*tmp;
        }
    }
};
