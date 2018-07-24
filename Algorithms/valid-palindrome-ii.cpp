https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        bool ck = true, ret = true, retR = true;
        while(l < r)
        {
            if(s[l] == s[r]) l++, r--;
            else if(ck)
            {
                ck = false;
                if(s[l+1] == s[r]) l++;
                else ret = false, l = r;
            }
            else ret = false, l = r;
        }
        ck = true;
        l = 0; r = s.size() - 1;
        while(l < r)
        {
            if(s[l] == s[r]) l++, r--;
            else if(ck)
            {
                ck = false;
                if(s[r-1] == s[l]) r--;
                else retR = false, l = r;
            }
            else retR = false, l = r;
        }
        return ret || retR;
    }
};
