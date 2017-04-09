//Problem Description: https://leetcode.com/contest/leetcode-weekly-contest-27/problems/reverse-words-in-a-string-iii
class Solution {
public:
    string reverseWords(string s) 
    {
        string ret;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[ i ] != ' ') 
            {
                int j = i;
                while(j < s.size() && s[ j ] != ' ') j++;
                for(int k = j - 1; k >= i; k--) ret += s[ k ];
                i = j - 1;
            }
            else ret += s[i];
        }
        return ret;
    }
};
