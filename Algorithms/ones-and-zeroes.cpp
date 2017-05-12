//Problem Description: https://leetcode.com/problems/ones-and-zeroes/#/description
int mamo[102][102][601];
class Solution {
public:
    struct data
    {
        int zero, one;
    }sstr[ 606 ];
    int len;
	
	int findMaxForm(vector<string>& strs, int m, int n) {
	    //puts("ok");
        memset(mamo, -1, sizeof mamo);
        len = strs.size();
        //puts("ok");
        string s = "01";
        for(int i = 0; i < len; i++)
        {
            sstr[i].one = sstr[i].zero = 0;
            for(int j = 0; j < strs[i].size(); j++)
            {
                sstr[i].zero += (strs[i][j] == s[0]) ? 1 : 0;
                sstr[i].one += (strs[i][j] == s[1]) ? 1 : 0;
            }
        }
        return DP(m, n, 0);
    }
    int DP(int m, int n, int s)
    {
        if(m < 0 || n < 0) return -1;
        if(s == len) return 0;
        int &ret = mamo[ m ][ n ][s];
        if(ret != -1) return ret;
        ret = DP(m, n, s + 1);
        ret = max(ret, 1 + DP(m - sstr[s].zero, n - sstr[s].one, s + 1));
        return ret;
    }
};
