https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ret = -1, len = strs.size();
        for(int i = 0, a, b, lena; i < len; i++)
        {
            lena = strs[i].size();
            bool mark = true;
            for(int j = 0, lenb; j < len; j++)
            {
                if(i == j) continue;
                lenb = strs[j].size();
                if(lenb < lena) continue;
                a = b = 0;
                while(a < lena && b < lenb)
                {
                    if(strs[i][a] == strs[j][b]) a++, b++;
                    else b++;
                }
                mark = a == lena ? false : mark;
                j = mark ? j : len;
            }
            ret = !mark ? ret : ret < lena ? lena : ret;
        }
        return ret;
    }
};
