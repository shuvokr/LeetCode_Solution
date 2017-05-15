//Problem Description: https://leetcode.com/problems/is-subsequence/#/description
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int tLen = t.size(), sLen = s.size(), a = 0;
        if(!sLen) return true;
        for(int i = 0; i < tLen; i++)
        {
            a += s[ a ] == t[ i ];
            if(a == sLen) return true;
        }
        return false;
    }
};
