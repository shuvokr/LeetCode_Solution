// Link: https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    bool mark[55][55];
    int newC, row, col, tag;
    vector<vector<int>> img;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        memset(mark, true, sizeof mark);
        img = image;
        tag = image[sr][sc];
        row = image.size(), col = image[0].size();
        DFS(sr, sc);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                image[i][j] = mark[i][j] ? image[i][j] : newColor;
        return image;
    }
    void DFS(int u, int v)
    {
        if(mark[u][v])
        {
            mark[u][v] = false;
            int direction1[] = {0, 0, 1, -1};
            int direction2[] = {1, -1, 0, 0};
            for(int i = 0; i < 4; i++)
            {
                int x = u + direction1[i], y = v + direction2[i];
                if(x > -1 && y > -1 && x < row && y < col && mark[x][y] && img[x][y] == tag) DFS(x, y);
            }
        }
    }
};
