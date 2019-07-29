// Link : https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int res = 2, a = 1, b = 1, c = 2;
        for(int i = 3; i < n; i++) {
            res = a + b + c;
            a = b; b = c; c = res;
        }
        return res;
    }
};
