// https://leetcode.com/problems/perfect-squares/#/description
class Solution {
public:
    unordered_map<int, int> mp;
    int numSquares(int n) {
        if(n == 0) return 0;
        if(mp.find(n) != mp.end()) return mp[n];
        int res = 1000000000;
        for(int i = sqrt(n);i;i--)
            res = min(res, 1 + numSquares(n - (i*i)));
        mp[ n ] = res;
        return res;
    }
};
