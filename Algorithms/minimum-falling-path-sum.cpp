https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int rowSize, colSize, mamo[110][110];
    vector<vector<int>> B;
    int minFallingPathSum(vector<vector<int>>& A) {
        B = A;
        rowSize = A.size();
        colSize = A[0].size();
        int result = 1000000001;
        for(int i = 0; i < rowSize; i++)
            for(int j = 0; j < colSize; j++) mamo[i][j] = result;
        for(int i = 0; i < colSize; i++) result = min(result, DP(0, i));
        return result;
    }
    
    int DP(int r, int c) {
		if(r == rowSize) return 0;
		int &ret = mamo[r][c];
		if(ret < 1000000001) return ret;
        int a = 1000000001, b = 1000000001, cc = 1000000001;
        if(c - 1 > -1) a = B[r][c] + DP(r + 1, c - 1);
        b = B[r][c] + DP(r + 1, c);
        if(c + 1 < colSize) cc = B[r][c] + DP(r + 1, c + 1);
		return ret = min(a, min(b, cc));
	}
};
