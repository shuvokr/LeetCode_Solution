//Problem Description: https://leetcode.com/problems/sort-characters-by-frequency
struct data
{
    int freq;
    char ch;
};
bool cmp(const data &x, const data &y)
{
    return x.freq > y.freq;
}
class Solution {
public:
    string frequencySort(string s) 
    {
        int len = s.size(), freq[ 130 ], cou = 0, t = 0;
        memset(freq, 0, sizeof freq);
        data mark[ 60 ];
        for(int i = 0; i < len; i++) freq[s[i]]++;
        for(int i = 0; i < 130; i++)
            if(freq[i]) { mark[ cou ].freq = freq[i]; mark[ cou ].ch = i; cou++; }
        sort(mark, mark + cou, cmp);
        char ret[ len+1 ];
        for(int i = 0; i < cou; i++)
            for(int j = 0; j < mark[i].freq; j++) ret[ t++ ] = mark[i].ch;
        ret[t] = NULL;
        return ret;
    }
};
