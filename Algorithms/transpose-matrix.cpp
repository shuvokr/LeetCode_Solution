// https://leetcode.com/problems/transpose-matrix/description/

typedef vector<int> vi;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int r = A.size(), c = A[0].size();
        vector<vi> ret;
        ret.assign(c, vi());
        for(int j = 0; j < c; j++)
            for(int i = 0; i < r; i++) ret[j].push_back(A[i][j]);
        return ret;
    }
};
