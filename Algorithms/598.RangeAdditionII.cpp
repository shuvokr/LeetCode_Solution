class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mnRow = m, mnCol = n;
        for(int i = 0; i < ops.size(); i++) {
            mnRow = mnRow < ops[i][0] ? mnRow : ops[i][0];
            mnCol = mnCol < ops[i][1] ? mnCol : ops[i][1];
        }
        return mnRow * mnCol;
    }
};
