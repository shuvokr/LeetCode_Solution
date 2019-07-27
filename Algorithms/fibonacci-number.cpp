// Link : https://leetcode.com/problems/fibonacci-number/
// Tag : find fibonacci(N)

class Solution {
public:
    int fib(int N) {
        if(!N) return 0;
        if(N == 1) return 1;
        return fib(N - 1) + fib(N - 2);
    }
};
