class Solution {
    string ss, tt;
public:
    vector<vector<int>> mamo;
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        mamo.assign(s.size(), vector<int>());
        ss = s; tt = t;
        for(int i = 0; i < s.size(); i++)
            for(int j = 0; j < t.size(); j++)
                mamo[i].push_back(-1);
        
        return DP(s.size() - 1, t.size() - 1);
    }
    int DP(int pos1, int pos2) {
        if(pos1 < pos2) return 0;
        if(pos2 < 0) return 1;
        
        int &ret = mamo[pos1][pos2];
        if(ret != -1) return ret;
        
        if(ss[pos1] == tt[pos2])
            ret = DP(pos1 - 1, pos2 - 1) + DP(pos1 - 1, pos2);
        else ret = DP(pos1 - 1, pos2);
        
        return ret;
    }
};
