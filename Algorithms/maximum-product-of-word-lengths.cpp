// https://leetcode.com/problems/maximum-product-of-word-lengths/#/description
class Solution {
public:
    struct data
    {
        bool mark[ 26 ];
    };
    int maxProduct(vector<string>& words) 
    {
        int len = words.size();
        if(!len) return 0;
        data marks[ len + 1 ];
        for(int i = 0; i < len; i++)
        {
            memset(marks[i].mark, false, sizeof marks[i].mark);
            int wLen = words[i].size();
            for(int j = 0; j < wLen; j++)
                marks[i].mark[ words[i][j] - 'a' ] = true;
        }
        
        int ret = 0;
        for(int i = 0; i < len; i++)
            for(int j = i + 1; j < len; j++)
            {
                bool flag = false;
                for(int k = 0; k < 26; k++)
                    if(marks[i].mark[k] || marks[j].mark[k])
                        if(marks[i].mark[k] == marks[j].mark[k])
                            flag = true, k = 26;
                if(flag) continue;
                int tmp = words[i].size() * words[j].size();
                ret = ret < tmp ? tmp : ret;
            }
        return ret;
    }
};
