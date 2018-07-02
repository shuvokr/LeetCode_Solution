// Link: https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row, col;
        int r = grid.size(), c = grid[0].size();
        for(int i = 0; i < r; i++)
        {
            int mx = -1;
            for(int j = 0; j < c; j++) mx = mx < grid[i][j] ? grid[i][j] : mx;
            row.push_back(mx);
        }
        for(int j = 0; j < c; j++)
        {
            int mx = -1;
            for(int i = 0; i < r; i++) mx = mx < grid[i][j] ? grid[i][j] : mx;
            col.push_back(mx);
        }
        int answer = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++) answer += row[i] < col[j] ? row[i] - grid[i][j] : col[j] - grid[i][j];
        return answer;
    }
};
