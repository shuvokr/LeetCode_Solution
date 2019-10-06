class Solution {
    string str, ptr;
    short int mamo[2001][2001];
public:
    bool isMatch(string s, string p) {
        str = s;
        ptr = p;
        for(int i = 0; i < s.size(); i++)
            for(int j = 0; j < p.size(); j++)
                mamo[i][j] = -1;
        for(int i = 0; i < ptr.size(); i++)
            ptr[i] = ptr[i] == '?' ? '.' : ptr[i];
        return DP(s.size() - 1, p.size() - 1);
    }
    bool DP(int s, int p) {
        if(s == -1 && p == -1) return true;
        if(p < 0) return false;
        if(s < 0) {
            while(p > -1 && ptr[p] == '*') p--;
            if(p == -1) return true;
            return false;
        }
        short int &ret = mamo[s][p];
        if(ret != -1) return ret;
        
        ret = false;
        if(ptr[p] == '.' || ptr[p] == str[s])
            ret = ret | DP(s - 1, p - 1);
        else if(ptr[p] == '*') {
            int pp = p, ss = s;
            while(pp > -1 && ptr[pp] == '*') pp--;
            if(pp == -1) return true;
            
            ret = ret | DP(s, pp);
            ss--;
            while(ss > -1) {
                ret = ret | DP(ss, pp);
                ss--;
            }
        }
        else ret = false;
        return ret;
    }
};
