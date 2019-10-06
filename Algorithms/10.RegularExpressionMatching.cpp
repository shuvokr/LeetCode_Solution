class Solution {
    string str, ptr;
    short int mamo[101][101];
public:
    bool isMatch(string s, string p) {
        str = s;
        ptr = p;
        memset(mamo, -1, sizeof mamo);
        return DP(s.size() - 1, p.size() - 1);
    }
    bool DP(int s, int p) {
        if(s == -1 && p == -1) return true;
        if(p < 0) return false;
        if(s < 0) {
           
            while(ptr[p] == '*') {
                while(p > -1 && ptr[p] == '*') p--;
                if(p == 0) return true;
                p--;
            }
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
            
            ret = ret | DP(s, pp - 1);
            if(ptr[pp] == '.' || ptr[pp] == str[ss]) {
                if(ptr[pp] == '.') {
                    while(ss > -1) {
                        ret = ret | DP(ss - 1, pp - 1);
                        ss--;
                    }
                }
                else {
                    char ch = str[s];
                    while(ss > -1 && str[ss] == ch) {
                        ret = ret | DP(ss - 1, pp - 1);
                        ss--;
                    }
                }
            }
            
        }
        else ret = false;
        return ret;
    }
};
