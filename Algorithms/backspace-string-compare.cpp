// Link: https://leetcode.com/problems/backspace-string-compare/description/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int lens = S.size() - 1, lent = T.size() - 1, cou1 = 0, cou2 = 0;
        for(;lens > -1 || lent > -1;)
        {
            if(lens > -1 && S[lens] == '#') {cou1++, lens--; continue;}
            if(lent > -1 && T[lent] == '#') {cou2++, lent--; continue;}
            
            if(lens > -1 && cou1) {cou1--, lens--; continue;}
            if(lent > -1 && cou2) {cou2--, lent--; continue;}
            
            if(lens < 0 && lent < 0) return true;
            if(S[lens] != T[lent]) return false;
            lens--; lent--;        
        }
        return true;
    }
};
