//Problem Description: https://leetcode.com/problems/longest-palindromic-subsequence
class Solution {
public:
    int mamo[1005][1005];
    string str;
    int longestPalindromeSubseq(string s) {
        str = s;
        memset(mamo, -1, sizeof mamo);
        return DP(0, s.size() - 1);
    }
    int DP(int s, int e)
    {
        if(s == e) return 1;
        if(s > e) return 0;
        int &ret = mamo[s][e];
        if(ret != -1) return ret;
        ret = 0;
        if(str[ s ] == str[ e ]) ret = 2 + DP(s + 1, e - 1);
        return ret = max(ret, max(DP(s + 1, e), DP(s, e - 1)));
    }
};
