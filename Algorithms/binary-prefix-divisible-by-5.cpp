// Link : https://leetcode.com/problems/binary-prefix-divisible-by-5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        int mod = 0;
        for(int i = 0; i < A.size(); i++){
            mod = mod << 1;
            mod += A[i];
            mod %= 5;
            if(mod) ret.push_back(false);
            else ret.push_back(true);
        }
        return ret;
    }
};
