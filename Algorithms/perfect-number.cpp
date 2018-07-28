// https://leetcode.com/problems/perfect-number/description/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int limit = (floor)(sqrt(num)) + 1, total = 1, tmp;
        for(int i = 2; i < limit; i++)
        {
            tmp = num / i;
            total += tmp * i == num && i != tmp ? tmp + i : tmp * i == num ? i : 0;
        }
        return total == num;
    }
};
