// Link : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string S) {
        string ret;
        for(int i = 0; i < S.size(); i++) {
            if(ret.size() == 0) ret += S[i];
            else if(ret[ret.size() - 1] != S[i]) ret += S[i];
            else ret.pop_back();
        }
        return ret;
    }
};
