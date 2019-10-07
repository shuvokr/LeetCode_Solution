class Solution {
    vector<vector<int>> s;
public:
    long long mamo[500][500];
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        s = triangle;
        for(int i = 0; i < s.size(); i++)
            for(int j = 0; j < i + 1; j++)
                mamo[i][j] = -1;
        return DP(0, 0);
    }
    long long DP(int r, int c) {
        if(r == s.size()) return 0;
        if(c < 0 || c >= s[r].size()) return INT_MAX;
        
        long long &ret = mamo[r][c];
        if(ret != -1) return ret;
        
        ret = INT_MAX;
        ret = min(ret, s[r][c] + DP(r + 1, c));
        ret = min(ret, s[r][c] + DP(r + 1, c + 1));
        
        return ret;
    }
};
