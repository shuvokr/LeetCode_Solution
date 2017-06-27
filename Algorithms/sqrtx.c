// https://leetcode.com/problems/sqrtx/#/description
int mySqrt(int x)
{
    if(!x) return 0;
    if(x == 1) return 1;
    long long low = 1, high = x >> 1, mid, xx = x;
    while(high - low > 1)
    {
        mid = (low+high)>>1ll;
        if(mid * mid > xx) high = mid - 1;
        else low = mid;
    }
    return high*high > xx ? (int)low : (int)high;
}
