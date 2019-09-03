// Link : https://leetcode.com/problems/decode-ways/

class Solution {
public:
    string str;
    int mamo[10005][2];
    int numDecodings(string s) {
        str = s;
        memset(mamo, -1, sizeof mamo);
        return DP(0, 0);
    }
    int DP(int pos, int state) {
        if(pos == str.size()) return 1;
        if(pos > str.size()) return 0;
        int &ret = mamo[pos][state];
        if(ret != -1) return ret;
        
        int a = 0;
        if(str[pos] != 48)
            a = DP(pos + 1, 0);
        int b = 0;
        if(pos + 1 < str.size()) {
            int num = str[pos]- 48;
            num *= 10;
            num += (str[pos+1] - 48);
            if(num < 27 && num > 9) 
                b = DP(pos + 2, 1);
        }
        return ret = a + b;
    }
};
