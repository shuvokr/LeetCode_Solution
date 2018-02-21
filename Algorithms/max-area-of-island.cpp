// Link: https://leetcode.com/problems/max-area-of-island/description/

class Solution {
public:
    vector<vector<int>> graph;
    int row, col, ret, mr;
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        row = grid.size(); ret = 0;
        if(!row) return 0;
        col = grid[0].size();
        graph = grid;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(!graph[i][j]) continue;
                mr = 0; DFS(i, j);
            }
        return ret;
    }
    void DFS(int u, int v)
    {
        mr++;
        graph[u][v] = 0;
            int dir1[] = {1, -1, 0, 0};
            int dir2[] = {0, 0, 1, -1};
            for(int i = 0; i < 4; i++)
            {
                int x = u + dir1[i], y = dir2[i] + v;
                if(x > -1 && y > -1 && x < row && y < col && graph[x][y]) DFS(x, y);
            }
        ret = mr < ret ? ret : mr;
    }
};
