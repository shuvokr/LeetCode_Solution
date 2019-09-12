class NumMatrix {
public:
    int mamo[ 1001 ][ 1001 ];
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[i].size(); j++)
                mamo[i][j] = j == 0 ? matrix[i][j] : matrix[i][j] + mamo[i][j - 1];
        
        for(int j = 0; j < matrix[0].size(); j++)
            for(int i = 0; i < matrix.size(); i++)
                mamo[i][j] = i == 0 ? mamo[i][j] : mamo[i][j] + mamo[i - 1][j];
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return totalSum(row2, col2) - totalSum(row1 - 1, col2) - totalSum(row2, col1 - 1) + totalSum(row1 - 1, col1 - 1);
    }
    
    int totalSum(int row, int col) {
        return row < 0 || col < 0 ? 0 : mamo[row][col];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
