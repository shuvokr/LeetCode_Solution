// https://leetcode.com/problems/reverse-string-ii/description/

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0, len = s.size(); i < len; i += k << 1)
        {
            int a = i, b = i + k - 1 < len ? i + k - 1 : len - 1;
            while(a < b) swap(s[a++], s[b--]);
        }
        return s;
    }
};
