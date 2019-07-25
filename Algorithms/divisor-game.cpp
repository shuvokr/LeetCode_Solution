// Link : https://leetcode.com/problems/divisor-game/

class Solution {
public:
    bool divisorGame(int N) {
        int x = N >> 1;
        return x << 1 == N;
    }
};
