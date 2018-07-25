//https://leetcode.com/problems/shortest-completing-word/description/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int a[26], b[26], len = words.size(), mx = -1, mnLen = 1000000001;
        string ret = "";
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        
        for(int i = licensePlate.size() - 1; i > -1; i--)
            if(isalpha(licensePlate[i])) a[tolower(licensePlate[i]) - 'a']++;
        
        for(int i = 0; i < len; i++)
        {
            int lens = words[i].size(), tot = 0;
            for(int j = 0; j < lens; j++) b[words[i][j] - 'a']++;
            for(int j = 0; j < lens; j++) tot += min(b[words[i][j] - 'a'], a[words[i][j] - 'a']), b[words[i][j] - 'a'] = 0;
            if(tot > mx || (tot == mx && lens < mnLen))
            {
                ret = words[i];
                mnLen = lens;
                mx = tot;
            }
        }
        return ret;
    }
};
