// Link: https://leetcode.com/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v = heights;
        int result = 0, len = v.size();
        sort(v.begin(), v.end());
        for(int i = 0; i < len; i++) result += (v[i] != heights[i]);
        return result;
    }
};
