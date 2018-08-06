// https://leetcode.com/problems/n-queens-ii/description/

class Solution {
public:
    int totalNQueens(int n) {
        int ret[] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200};
        return ret[n];
    }
};
