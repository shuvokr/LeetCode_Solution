// Link : https://leetcode.com/problems/di-string-match
// Tag : Decode

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> result;
        int len = S.size(), small = 0, big = len;
        for(int i = 0; i < len; i++) {
            if(S[i] == 'I') result.push_back(small++);
            else result.push_back(big--);
        }
        if(S[len - 1] == 'I') result.push_back(big);
        else result.push_back(small);
        return result;
    }
};
