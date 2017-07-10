// https://leetcode.com/problems/set-matrix-zeroes/#/description
class Solution {
    const int setIt = (1 << 27)-1009, pik = (1 << 28)-9001;
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        cout << setIt << endl;
        if(!matrix.size()) return;
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(!matrix[i][j] || matrix[i][j] == pik)
                {
                    for(int K = 0; K < col; K++) matrix[i][K] = matrix[i][K] == 0 || matrix[i][K] == pik ? pik : setIt;
                    for(int K = 0; K < row; K++) matrix[K][j] = matrix[K][j] == 0 || matrix[K][j] == pik ? pik : setIt;
                }
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) matrix[i][j] = matrix[i][j] == setIt || matrix[i][j] == pik ? 0 : matrix[i][j];
    }
};
