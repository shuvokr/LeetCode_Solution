//https://leetcode.com/problems/game-of-life/#/description
class Solution {
    int diraction1[8] = {-1, 0, 0, 1, 1, -1, -1, 1};
    int diraction2[8] = {0, -1, 1, 0, 1, -1, 1, -1};
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int row = board.size(), col = board[0].size();
        if(row && col)
        {
          bool mark[row][col];
          for(int i = 0; i < row; i++)
              for(int o = 0; o < col; o++)
              {
                  int a, b, dead = 0;
                  for(int g = 0; g < 8; g++)
                  {
                      a = i + diraction1[g];
                      b = o + diraction2[g];
                      if(a < 0 || a >= row || b < 0 || b >= col) continue;
                      dead += board[a][b];
                  }
                  mark[i][o] = (dead > 3) ? 0 : (board[i][o] == 0 && dead == 3) ? 1 :

                  (board[i][o] == 1 && (dead == 2 || dead == 3)) ? 1 : dead < 2 ? 0 : board[i][o];
              }

          for(int o = 0; o < col; o++)
              for(int i = 0; i < row; i++) board[i][o] = mark[i][o];
        }
    }
};
/*
    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*/
