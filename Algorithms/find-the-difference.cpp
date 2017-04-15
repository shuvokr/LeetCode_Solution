//Problem Description: https://leetcode.com/problems/find-the-difference
class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int mark[ 26 ], len = s.size();
        memset(mark, 0, sizeof mark);
        for(int i = 0; i < len; i++) mark[s[i]-97]++;
        
        len = t.size();
        for(int i = 0; i < len; i++) 
        {
            mark[t[i]-97]--;
            if(mark[t[i]-97] < 0) return t[i];
        }
    }
};
