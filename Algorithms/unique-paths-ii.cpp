// https://leetcode.com/problems/unique-paths-ii/#/description
class Solution {
public:
    int mamo[ 101 ][ 101 ];
    vector< vector<int> > v;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(mamo, -1 , sizeof mamo);
        v = obstacleGrid;
        return DP(obstacleGrid.size() - 1, obstacleGrid[0].size() - 1);
    }
    int DP(int a, int b)
    {
        if(a < 0 || b < 0) return 0;
        if(v[ a ][ b ]) return 0;
        if(a == 0 && b == 0) return 1;
        int &ret = mamo[ a ][ b ];
        if(ret != -1) return ret;
        ret = DP(a - 1, b) + DP(a, b - 1);
        return ret;
    }
};
