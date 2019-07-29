// Link : https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    bool mark[ 10 ];
    int kkk, nnn;
    string res, ret;
    string getPermutation(int n, int k) {
        memset(mark, false, sizeof mark);
        kkk = k; nnn = n;
        solve(0);
        return ret;
    }
    void solve(int n) {
        if(!kkk) return;
        if(n == nnn) {
            kkk--;
            ret = res;
            return;
        }
        for(int i = 1; i <= nnn; i++) {
            if(mark[i]) continue;
            mark[i] = true;
            res += (i + 48);
            solve(n + 1);
            mark[i] = false;
            res.pop_back();
        }
    }
};
