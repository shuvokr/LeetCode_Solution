https://leetcode.com/problems/to-lower-case/description/

class Solution {
public:
    string toLowerCase(string str) {
        for(int i = str.size() - 1; i > -1; i--) str[i] = tolower(str[i]);
        return str;
    }
};
