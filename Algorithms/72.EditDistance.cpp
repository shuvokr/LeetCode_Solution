class Solution {
    string a, b;
    int mamo[1001][1001];
public:
    int minDistance(string word1, string word2) {
        a = word1;
        b = word2;
        int len1 = a.size(), len2 = b.size();
        for(int i = 0; i < len1; i++)
            for(int j = 0; j < len2; j++)
                    mamo[i][j] = -1;
        
        return solve(len1 - 1, len2 - 1);
    }
    int solve(int pos1, int pos2) {
        if(pos2 < 0) return pos1 + 1;
        if(pos1 < 0) return pos2 + 1;
        int &ret = mamo[pos1][pos2];
        if(ret != -1) return ret;
        
        ret = INT_MAX;
        if(a[pos1] == b[pos2])
            ret = min(ret, solve(pos1 - 1, pos2 - 1)); // no change
        
        ret = min(ret, 1 + solve(pos1, pos2 - 1)); // insert
        ret = min(ret, 1 + solve(pos1 - 1, pos2)); // delete
        ret = min(ret, 1 + solve(pos1 - 1, pos2 - 1)); // replace
        
        return ret;
    }
};
