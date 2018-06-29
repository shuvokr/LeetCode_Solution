// Link: https://leetcode.com/problems/binary-number-with-alternating-bits/description/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit, xbit = n % 2; n >>= 1;
        while(n)
        {
            bit = n % 2; n >>= 1;
            if(bit == xbit) return false;
            xbit = bit;
        }
        return true;
    }
};
