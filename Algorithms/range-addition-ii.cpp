// Link : https://leetcode.com/problems/range-addition-ii

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mnRow = 140001, mnCol = 140001;
        for(int i = 0; i < ops.size(); i++) {
            mnRow = mnRow < ops[i][0] ? mnRow : ops[i][0];
            mnCol = mnCol < ops[i][1] ? mnCol : ops[i][1];
        }
        return mnRow * mnCol;
    }
};
