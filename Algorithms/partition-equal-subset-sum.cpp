//Problem Description: https://leetcode.com/problems/partition-equal-subset-sum/#/description
int mamo[ 210 ][ 2 ][10010];
class Solution {
public:
    int total;
    vector<int> v;
    bool canPartition(vector<int>& nums) 
    {
        if(nums.size() == 0) return true;
        v = nums;
        total = 0;
        for(int i = 0; i < nums.size(); i++)
            total += nums[ i ];
        if(total&1) return false;
        memset(mamo, -1, sizeof mamo);
        total >>= 1;
        return DP(nums.size() - 1, 0, total);
    }
    int DP(int pos, int flag, int tot)
    {
        if(tot == 0) return true;
        if(pos == -1 || tot < 0) return 0;
        int &ret = mamo[ pos ][ flag ][tot];
        if(ret != -1) return ret;
        int a = DP(pos - 1, 1, tot - v[pos]);
        int b = DP(pos - 1, 0, tot);
        ret = a | b;
        return ret;
    }
};
