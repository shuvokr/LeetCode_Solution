https://leetcode.com/problems/excel-sheet-column-number/description/

class Solution {
public:
    int titleToNumber(string s) {
        int neg = 'A' - 1, mul = 1, answer = 0;
        for(int i = s.size() - 1; i > -1; i--) answer += mul * (s[i] - neg), mul *= 26;
        return answer;
    }
};
