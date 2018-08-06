// https://leetcode.com/problems/n-queens/description/

class Solution {
public:
    vector<vector<string>> str;
    vector<string> tmp;
    string t;
    int N;
    vector<vector<string>> solveNQueens(int n) {
        for(int i = 0; i < n; i++) t = t + ".";
        for(int i = 0; i < n; i++) tmp.push_back(t);
        N = n; solve(n - 1);
        return str;
    }
    void solve(int i)
    {
        if(i == -1)
        {
            str.push_back(tmp);
            return;
        }
        for(int j = 0; j < N; j++)
            if(isok(i, j))
            {
                tmp[i][j] = 'Q';
                solve(i - 1);
                tmp[i][j] = '.';
            }
    }
    bool isok(int r, int c)
    {
        for(int i = 0; i < N; i++)
            if(tmp[r][i] == 'Q' && i != c) return false;
        for(int i = 0; i < N; i++)
            if(tmp[i][c] == 'Q' && i != r) return false;
        
        for(int i = r + 1, j = c + 1; i < N && j < N; i++, j++) if(tmp[i][j] == 'Q') return false;
        for(int i = r - 1, j = c - 1; i > -1 && j > -1; i--, j--) if(tmp[i][j] == 'Q') return false;
        for(int i = r + 1, j = c - 1; i < N && j > -1; i++, j--) if(tmp[i][j] == 'Q') return false;
        for(int i = r - 1, j = c + 1; i > -1 && j < N; i--, j++) if(tmp[i][j] == 'Q') return false;
        
        return true;
    }
};
