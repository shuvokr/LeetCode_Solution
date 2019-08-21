// Link : https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    int depth[2001];
    vector< vector<int> > graph;
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if(dislikes.size() == 0) return true;
        for(int i = 1; i <= N; i++) depth[i] = INT_MAX;
        graph.assign(N+1, vector<int>());
        for(int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        bool ret = true;
        for(int i = 1; i <= N; i++) 
            if(depth[i] == INT_MAX) ret &= BFS(i);
        return ret;
    }
    bool BFS(int u) {
        depth[u] = 1;
        queue<int> myQueue;
        myQueue.push( u );
        while( !myQueue.empty() ) {
            u = myQueue.front(); myQueue.pop();
            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if(depth[v] == INT_MAX) {
                    depth[v] = depth[u] + 1;
                    myQueue.push(v);
                }
                else if(depth[u] == depth[v]) return false;
            }
        }
        return true;
    }
};
