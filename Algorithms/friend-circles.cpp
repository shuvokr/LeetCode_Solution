// https://leetcode.com/problems/friend-circles/#/description
class Solution {
public:
    bool mark[ 222 ];
    vector< vector<int> > graph;
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        graph.assign(n + 5, vector<int>());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(i == j || !M[i][j]) continue;
                graph[i].push_back(j);
            }
        memset(mark, true, sizeof mark);
        int ret = 0;
        for(int i = 0; i < n; i++)
        {
            if(!mark[ i ]) continue;
            ret++;
            mark[ i ] = false;
            DFS( i );
        }
        return ret;
    }
    void DFS(int u)
    {
        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[ u ][ i ];
            if(!mark[ v ]) continue;
            mark[ v ] = false;
            DFS( v );
        }
    }
};
