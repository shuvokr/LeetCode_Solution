// Link : https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int mark[N + 1] = {0}, ret = -1;
        bool touch[N + 1] = {false};
        for(int i = 0; i < trust.size(); i++) {
            mark[ trust[i][1] ]++;
            touch[ trust[i][0] ] = true;
        }
        for(int i = 1; i <= N; i++) {
            if(mark[i] == N - 1 && !touch[i]) {
                if(ret != -1) return -1;
                else ret = i;
            }
        }
        return ret;
    }
};
