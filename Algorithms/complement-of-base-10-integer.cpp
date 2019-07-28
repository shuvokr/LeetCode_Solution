// Link : https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int N) {
        if(!N) return 1;
        vector<int> binary;
        while(N) {
            binary.push_back(N&1);
            N >>= 1;
        }
        for(int i = 0; i < binary.size(); i++)
            binary[i] = binary[i] == 0 ? 1 : 0;
        long long ret = 0LL, val = 1LL;
        for(int i = 0; i < binary.size(); i++)
            ret += val * binary[i], val <<= 1;
        return ret;
    }
};
