//Problem Description: https://leetcode.com/problems/longest-common-prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ret = "";
        int len = strs.size(), j = 0;
        if(len == 1)
        {
            ret = strs[ 0 ];
            return ret;
        }
        bool flag = true;
        if( len )
        while( flag )
        {
            if(len> 1)
            {
                for(int i = 1; i < len; i++)
                {
                    if(strs[i].size() > j && strs[i-1].size() > j)
                    {
                        if(strs[i][j] != strs[i-1][j]) i = len, flag = false;
                    }
                    else flag = false;
                }
            }
            else break;
            if( flag ) ret += strs[0][j];
            j++;
        }
        return ret;
    }
};
