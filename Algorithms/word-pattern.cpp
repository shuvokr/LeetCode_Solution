// Link: https://leetcode.com/problems/word-pattern/description/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string s;
        int lenp = pattern.size(), len = str.size(), k = 0;
        map<char, bool> patMark;
        map<string, char> sMark;
        for(int i = 0; i < len; i++)
        {
            if(str[i] == ' ' || i + 1 == len)
            {
                if(i + 1 == len) s += str[i];
                if(patMark.find(pattern[k]) == patMark.end() && sMark.find(s) == sMark.end()) 
                {
                    sMark[s] = pattern[k];
                    patMark[pattern[k++]] = true;
                    s = "";
                }
                else if(patMark.find(pattern[k]) != patMark.end() && sMark.find(s) != sMark.end() && sMark[s] == pattern[k++]) s = "";
                else return false;
            }
            else s += str[i];
        }
        return k == lenp;
    }
};
