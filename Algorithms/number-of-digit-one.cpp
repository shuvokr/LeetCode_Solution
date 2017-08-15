// https://leetcode.com/problems/number-of-digit-one/description/
class Solution {
    struct data
    {
        int one, all, baki, last, result;
    }res, tm;
public:
    int countDigitOne(int n) {
        int next = 1, tp = 0;
        res.one = res.baki = res.last = res.result = res.all = 0;
        while( n )
        {
            int tmp = n % 10; n /= 10;
            tm = res;
            res.one = tmp > 1 ? next : 0;
            res.all = tm.all * 10 + next;
            res.baki = tmp * tm.all;
            res.last = tmp == 1 ? tm.result + tp + 1 : tm.result;
            res.result = res.one + res.baki + res.last;
            
            tp += tmp * next;
            next *= 10;
        }
        return res.result;
    }
};
