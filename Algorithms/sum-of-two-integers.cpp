// Link: https://leetcode.com/problems/sum-of-two-integers/description/

class Solution {
public:
    int getSum(int a, int b) {
        for(int c = a&b;b; c = a&b)
        {
            a ^= b;
            b = c<<1;
        }
        return a;
    }
};
