// Link: https://leetcode.com/problems/number-of-lines-to-write-string/description/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int sumUp = 0, line = 1, len = S.size();
        for(int i = 0, temp; i < len; i++)
        {
            temp = widths[ S[i] - 'a' ];
            sumUp += temp;
            line += sumUp > 100 ? 1 : 0;
            sumUp = sumUp > 100 ? temp : sumUp;
        }
        widths.clear();
        widths.push_back(line);
        widths.push_back(sumUp);
        return widths;
    }
};
