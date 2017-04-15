//Problem Description: https://leetcode.com/problems/longest-palindrome
class Solution {
public:
    int longestPalindrome(string s) 
    {
        int ret = 0, mark[ 130 ], len = s.size(), flag = 0;
        memset(mark, 0, sizeof mark);
        for(int i = 0; i < len; i++) mark[s[i]]++;
        for(int i = 0; i < 130; i++)
        {
            flag = mark[i]&1 ? 1 : flag;
            ret += mark[i]&1 ? mark[i] - 1 : mark[i];
        }
        ret += flag;
        return ret;
    }
};
