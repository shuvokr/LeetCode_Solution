// Link: https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows) return vector<vector<int>>();
        vector<vector<int>> ret(numRows, vector<int>());
        ret[0].push_back(1);
        if(numRows == 1) return ret;
        for(int i = 1; i < numRows; i++)
        {
            ret[i].push_back(1);
            for(int j = 1; j < i; j++) ret[i].push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            ret[i].push_back(1);
        }
        return ret;
    }
};
