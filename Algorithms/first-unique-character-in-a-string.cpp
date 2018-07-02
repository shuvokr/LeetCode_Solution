// Link: https://leetcode.com/problems/first-unique-character-in-a-string/description/

class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size(), freq[ 26 ];
        memset(freq, 0, sizeof freq);
        for(int i = 0; i < len; i++) freq[s[i]-'a']++;
        for(int i = 0; i < len; i++) if(freq[s[i]-'a'] == 1) return i;
        return -1;
    }
};
