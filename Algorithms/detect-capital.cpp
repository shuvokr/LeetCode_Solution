// https://leetcode.com/problems/detect-capital/description/

class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool allBig = word[0] < 97, allSmall = word[0] > 96, firstBig = word[0] < 97;
        for(int i = 1, len = word.size(); i < len; i++)
        {
            if(word[ i ] > 96) { allBig = false; if(!allSmall && !firstBig) return false; }
            else { allSmall = firstBig = false; if(!allBig) return false; }
        }
        return true;
    }
};
