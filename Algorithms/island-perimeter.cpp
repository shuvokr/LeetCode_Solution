//Problem Description: https://leetcode.com/problems/island-perimeter
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int perimeter = 0, row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j])
                {
                    if(i - 1 < 0) perimeter++;
                    if(i + 1 >= row) perimeter++;
                    if(j - 1 < 0) perimeter++;
                    if(j + 1 >= col) perimeter++;
                    if(i + 1 < row) perimeter += !grid[i+ 1][j];
                    if(i - 1 >= 0) perimeter += !grid[i- 1][j];
                    if(j + 1 < col) perimeter += !grid[i][j+ 1];
                    if(j - 1 >= 0) perimeter += !grid[i][j- 1];
                }
            }
        return perimeter;
    }
};
