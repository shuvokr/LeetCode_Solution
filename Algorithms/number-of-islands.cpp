// https://leetcode.com/problems/number-of-islands/#/description
class Solution {
public:
    bool mark[ 2002 ][ 2002 ];
    int n, m;
    vector< vector<char> >v;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        memset(mark, true, sizeof mark);
        n = grid.size();
        m = grid[0].size();
        v = grid;
        cout << n <<  " " << m << endl;
        int ret = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(grid[ i ][ j ] == '0') continue;
                if(!mark[ i ][ j ]) continue;
                ret++;
                mark[ i ][ j ] = false;
                DFS(i, j);
            }
        return ret;
    }
    void DFS(int i, int j)
    {
        if(i < 0 || j < 0 || i >= n || j >= m) return;
        if(i+1 < n && mark[i + 1][ j ] && v[i+1][ j ] == '1')
        {
            mark[i+1][j] = false;
            DFS(i+1, j);
        }
        if(i-1 > -1 && mark[i - 1][ j ] && v[i-1][ j ] == '1')
        {
            mark[i-1][j] = false;
            DFS(i-1, j);
        }
        if(j+1 < m && mark[i][ j+1 ] && v[i][ j+1 ] == '1')
        {
            mark[i][j+1] = false;
            DFS(i, j+1);
        }
        if(j-1 > -1 && mark[i][ j-1 ] && v[i][ j-1 ] == '1')
        {
            mark[i][j-1] = false;
            DFS(i, j-1);
        }
    }
};
