class Solution {
public:
    vector<vector<int>> vv, dis;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        vv.assign(matrix.size(), vector<int>());
        dis.assign(matrix.size(), vector<int>());
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++) {
                dis[i].push_back(INT_MAX);
                vv[i].push_back(matrix[i][j]);
            }
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[i].size(); j++)
                if(dis[i][j] == INT_MAX) {
                    dis[i][j] = 0;
                    solve(i, j);
                }
        
        int ret = INT_MIN;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[i].size(); j++)
                ret = max(ret, dis[i][j]);
        
        return ret + 1;
    }
    void solve(int u, int v) {
        if(!isok(u, v)) return;
        int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
        int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
        for(int i = 0; i < 4; i++) {
            int a = u + diraction1[i], b = v + diraction2[i];
            if(isok(a, b) && vv[a][b] > vv[u][v]) {
                if(dis[a][b] == INT_MAX) {
                    dis[a][b] = dis[u][v] + 1;
                    solve(a, b);
                }
                else {
                    if(dis[u][v] + 1 > dis[a][b]) {
                        dis[a][b] = dis[u][v] + 1;
                        solve(a, b);
                    }
                }
            }
        }
    }
    bool isok(int u, int v) {
        return (u >= vv.size() || u < 0 || v >= vv[u].size() || v < 0) ? false : true;
    }
};
