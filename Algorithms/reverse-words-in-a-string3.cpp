// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution {
public:
    string reverseWords(string s) {
        int length = s.size(), point = 0, lPoint, ind = 0;
        for(int i = 0; i < length; i++)
        {
            if(s[i] == ' ' || i + 1 == length)
            {
                lPoint = i + 1 == length ? i : i - 1;
                while(lPoint > point) swap(s[point++], s[lPoint--]);
                point = i + 1;
            }
        }
        return s;
    }
};
