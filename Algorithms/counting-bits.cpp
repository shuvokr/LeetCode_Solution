//https://leetcode.com/problems/counting-bits/#/description
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        ret.push_back(0);
        for(int i = 1; i <= num; i++)
        {
            int t = 0, n = i;
            while(n) t += (n % 2), n >>= 1;
            ret.push_back(t);
        }
        return ret;
    }
};
