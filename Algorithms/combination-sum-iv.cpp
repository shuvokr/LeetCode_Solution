//Problem Description: https://leetcode.com/problems/combination-sum-iv/#/description
int mamo[1010][10010], len;
vector<int> v;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        v = nums;
        len = nums.size();
        memset(mamo, -1, sizeof mamo);
        return DP(len - 1, target);
    }
    int DP(int pos, int t)
    {
        if(t == 0) return 1;
        if(pos < 0 || t < 0) return 0;
        int &ret = mamo[pos][t];
        if(ret != -1) return ret;
        int a = DP(pos - 1, t);
        int b = DP(len - 1, t - v[pos]);
        return ret = a + b;
    }
};
