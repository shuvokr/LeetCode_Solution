// Link = https://leetcode.com/problems/arranging-coins/description/

class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0, right = 123456, mid;
        while(right - left > 1)
        {
            mid = (left + right) >> 1ll;
            if((mid * (mid + 1)) >> 1ll > n) right = mid - 1;
            else left = mid;
        }
        if((right * (right + 1)) >> 1ll > n) return left;
        return right;
    }
};
