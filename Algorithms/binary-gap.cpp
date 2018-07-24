https://leetcode.com/problems/binary-gap/description/

class Solution {
public:
    int binaryGap(int N) {
        bool ck = false;
        int ret = 0, mx = 0, one = 0;
        for(;N && !(N&1);N >>= 1);
        for(;N;N >>= 1)
        {
            mx += !(N&1);
            one += (N&1);
            ret = mx < ret ? ret : mx;
            mx = N&1 ? 0 : mx;
        }
        ret = one < 2 ? 0 : ret + 1;
        return ret;
    }
};
