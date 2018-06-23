// Link: https://leetcode.com/problems/flipping-an-image/description/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row_col = A.size();
        for(int i = 0; i < row_col; i++)
            for(int temp, j = 0, k = row_col - 1; j <= k; j++, k--)
            {
                temp = A[i][j];
                A[i][j] = A[i][k] ? 0 : 1;
                A[i][k] = temp ? 0 : 1;
            }
        return A;
    }
};
