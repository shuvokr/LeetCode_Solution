// https://leetcode.com/problems/sum-of-square-numbers/description/

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 3) return true;
        int x = sqrt(c) + 1;
        for(int i = 0, p = i * i, d = sqrt(c - p); i < x; i++, p = i * i, d = sqrt(c - p))
            if(d * d + p == c) return true;
        return false;
    }
};
