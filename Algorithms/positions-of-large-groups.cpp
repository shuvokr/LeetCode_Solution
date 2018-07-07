// https://leetcode.com/problems/positions-of-large-groups/description/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<int> v;
        int len = S.size();
        for(int i = 0, j = i + 1; i < len; i++, j = i + 1)
        {
            char ch = S[i];
            for(;j < len && S[j] == ch; j++);
            if(j - i > 2)
            {
                v.push_back(i);
                v.push_back(j - 1);
                i = j - 1;
            }
        }
        if(v.empty()) return vector<vector<int>>();
        else
        {
            len = v.size();
            len >>= 1;
            vector<vector<int>> ret; 
            ret.assign(len, vector<int>());
            len <<= 1;
            for(int i = 0, j = 0; i < len; i += 2, j++) 
            {
                ret[j].push_back(v[i]);
                ret[j].push_back(v[i+1]);
            }
            return ret;
        }
    }
};
