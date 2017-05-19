// https://leetcode.com/problems/climbing-stairs/#/description
class Solution {
public:
    unordered_map<int, int> mp;
    
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(mp.find(n) != mp.end()) return mp[ n ];
        int ret = climbStairs(n - 2) + climbStairs(n - 1);
        return mp[ n ] = ret;
    }
};
