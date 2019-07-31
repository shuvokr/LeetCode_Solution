// Link : https://leetcode.com/problems/knight-probability-in-chessboard

class Solution {
public:
    double mamo[ 101 ][ 26 ][ 26 ];
    double knightProbability(int N, int K, int r, int c) {
        if(K == 0) return 1.0;
        double &ret = mamo[ K ][ r ][ c ];
        if(ret) return ret;
        ret = 0.0;
        int directionRow[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int directionCol[] = {1, -1, 1, -1, 2, -2, 2, -2};
        for(int i = 0; i < 8; i++) {
            int newR = r + directionRow[i];
            int newC = c + directionCol[i];
            if(!isOk(newR, newC, N)) continue;
            ret += (knightProbability(N, K - 1, newR, newC) / 8.0);
        }
        return ret;
    }
    bool isOk(int r, int c, int n) {
        return r > -1 && r < n && c > -1 && c < n;
    }
};
