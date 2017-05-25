// https://leetcode.com/problems/out-of-boundary-paths/#/description
class Solution {
public:
    int mamo[ 55 ][ 55 ][ 5 ][ 55 ];
    int modValue, hight, width;
    int findPaths(int m, int n, int N, int i, int j) {
        memset(mamo, -1, sizeof mamo);
        hight = m; width = n;
        modValue = 1000000007;
        return DP(i, j, 0, N);
    }
    int DP(int i, int j, int dir, int N)
    {
        if((N >= 0) && isok(i, j)) return 1;
        if(N < 0) return 0;
        int &ret = mamo[ i ][ j ][ dir ][ N ];
        if(ret != -1) return ret;
        ret = 0;
        int a = DP(i + 1, j, 0, N - 1);
        int b = DP(i - 1, j, 1, N - 1);
        int c = DP(i, j + 1, 2, N - 1);
        int d = DP(i, j - 1, 3, N - 1);
        ret = ((a % modValue) + (b % modValue)) % modValue;
        ret = (ret + (c % modValue)) % modValue;
        ret = (ret + (d % modValue)) % modValue;
        return ret;
    }
    bool isok(int i, int j)
    {
        return (i < 0 || j < 0 || i >= hight || j >= width);
    }
};
