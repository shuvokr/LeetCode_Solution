https://leetcode.com/problems/most-common-word/description/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string str = "", answer;
        map<string, int> mp, freq;
        int lenp = paragraph.size(), lenb = banned.size(), mx = -1;
        for(int k = 0, len; k < lenb; k++)
        {
            len = banned[k].size();
            for(int i = 0, j; i < len; i++)
            {
                if(!islower(banned[k][i])) continue;
                str = "";
                for(j = i; j < len && islower(banned[k][j]); j++) str += banned[k][j];
                mp[str] = 1; i = j;
            }
        }
        for(int i = 0, j; i < lenp; i++)
        {
            if(!isalpha(paragraph[i])) continue;
            str = "";
            for(j = i; j < lenp && isalpha(paragraph[j]); j++) str += tolower(paragraph[j]);
            i = j;
            if(mp.find(str) == mp.end()) freq[str]++;
            if(mx < freq[str])
            {
                mx = freq[str];
                answer = str;
            }
        }
        return answer;
    }
};
