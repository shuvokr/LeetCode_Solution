// Link: https://leetcode.com/problems/toeplitz-matrix/description/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), a = 1, b = 1;
        for(int i = 0; i < row; i++)
        {
            a = i+1; b = 1;
            while(a < row && b < col)
                if(matrix[a][b] != matrix[a - 1][b - 1]) return false;
                else a++, b++;
        }
        for(int i = 0; i < col; i++)
        {
            a = 1; b = i+1;
            while(a < row && b < col)
                if(matrix[a][b] != matrix[a - 1][b - 1]) return false;
                else a++, b++;
        }
        return true;
    }
};
