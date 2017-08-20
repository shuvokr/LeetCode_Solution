// https://leetcode.com/problems/palindromic-substrings/description

string str;
int mamo[ 1001 ][ 1001 ], mamo2[1001][1001];
class Solution {
public:
    int countSubstrings(string s) {
        str = s;
        memset(mamo, -1, sizeof mamo);
        memset(mamo2, -1, sizeof mamo2);
        return DP(0, str.size() - 1);
    }
    int DP(int left, int right)
    {
        if(left == right) return 1;
        if(left > right) return 0;
        int &ret = mamo[ left ][ right ];
        if(ret != -1) return ret;
        return ret =  DP(left + 1, right) + DP(left, right - 1) + isPalindrom(left, right) - DP(left + 1, right - 1);
    }
    bool isPalindrom(int L, int R)
    {
        if(L >= R) return true;
        int &ret = mamo2[L][R];
        if(ret != -1) return ret;
        ret = true;
        return ret = ret && (str[L] == str[R] ? isPalindrom(L + 1, R - 1) : false);
    }
};
