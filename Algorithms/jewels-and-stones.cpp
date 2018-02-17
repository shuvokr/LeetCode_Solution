// https://leetcode.com/problems/jewels-and-stones/description/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int frequency[ 130 ], len = S.size(), ret = 0;
        memset(frequency, 0, sizeof frequency);
        for(int i = 0; i < len; i++) frequency[ S[i] ]++; len = J.size();
        for(int i = 0; i < len; i++) ret += frequency[ J[i] ];
        return ret;
    }
};
