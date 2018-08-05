// https://leetcode.com/contest/weekly-contest-96/problems/projection-area-of-3d-shapes/

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int r = grid.size(), ar[55][55], ret = 0;
        memset(ar, 0, sizeof ar);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < r; j++) ar[i][j] = grid[i][j], ret += (bool)(grid[i][j]);
        for(int i = 0; i < 51; i++)
        {
            int mx = 0;
            for(int j = 50; j > -1; j--)
                mx = max(mx, ar[j][i]);
            ret += mx;
        }
        for(int i = 0; i < 51; i++)
        {
            int mx = 0;
            for(int j = 50; j > -1; j--)
                mx = max(mx, ar[i][j]);
            ret += mx;
        }
        return ret;
    }
};
