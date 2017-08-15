// https://leetcode.com/problems/factorial-trailing-zeroes/description/
class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        int ret = n/5;
        return ret + trailingZeroes(ret);
    }
};
