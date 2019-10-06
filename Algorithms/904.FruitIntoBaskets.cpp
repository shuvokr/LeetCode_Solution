class Solution {
public:
    vector<int> tre;
    int mamo[40001][2][2];
    int totalFruit(vector<int>& tree) {
        tre = tree;
        memset(mamo, -1, sizeof mamo);
        return solve(tree.size() - 1, 0, 0, 40000, 40000);
    }
    int solve(int pos, int o, int t, int basketOne, int basketTwo) {
        
        if(pos < 0) return 0;
        if(o && t && tre[pos] != basketOne && tre[pos] != basketTwo) return 0;
        
        int &ret = mamo[pos][o][t];
        if(ret != -1) return ret;
        
        if(!o) {
            ret = solve(pos - 1, o, t, basketOne, basketTwo);
            ret = max(ret, 1 + solve(pos - 1, 1, t, tre[pos], basketTwo));
        }
        else {
            if(tre[pos] == basketOne) {
                ret = max(ret, 1 + solve(pos - 1, o, t, basketOne, basketTwo));
            }
            else ret = max(ret, 1 + solve(pos - 1, o, 1, basketOne, tre[pos]));
        }
        return ret;
    }
};
