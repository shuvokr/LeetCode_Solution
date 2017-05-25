// https://leetcode.com/problems/student-attendance-record-ii/#/description
int mamo[ 100001 ][ 2 ][ 3 ], mod;
class Solution {
public:
    int checkRecord(int n) {
        mod = 1000000007;
        memset(mamo, -1, sizeof mamo);
        return DP(n, 0, 0);
    }
    int DP(int pos, int A, int L)
    {
        if(pos == 0) return 1;
        int &ret = mamo[ pos ][ A ][ L ];
        if(ret != -1) return ret;
        ret = DP(pos - 1, A, 0);
        int a = 0, b = 0, c = 0;
        if(A == 0) 
            a = DP(pos - 1, 1, 0);
        if(L == 0)
            b = DP(pos - 1, A, 1);
        if(L == 1)
            c = DP(pos - 1, A, 2);
        
        ret %= mod;
        ret = (ret + (a % mod)) % mod;
        ret = (ret + (b % mod)) % mod;
        ret = (ret + (c % mod)) % mod;
        return ret;
    }
};
