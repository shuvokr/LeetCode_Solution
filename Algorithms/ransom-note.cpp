//Problem Description: https://leetcode.com/problems/ransom-note
class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int ar[ 26 ], tmp[ 26 ];
        memset(ar, 0, sizeof ar);
        memset(tmp, 0, sizeof tmp);
        for(int i = 0; i < ransomNote.size(); i++)
        {
            char ch = ransomNote[ i ];
            ar[ch - 'a']++;
        }
        for(int i = 0; i < magazine.size(); i++)
        {
            char ch = magazine[ i ];
            tmp[ch - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(ar[ i ] > tmp[ i ]) return false;
        }
        return true;
    }
};
