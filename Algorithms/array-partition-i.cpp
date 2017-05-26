// https://leetcode.com/problems/array-partition-i/#/description
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = nums.size() - 2;
        int ret = 0;
        while(i > -1)
        {
            ret += nums[ i ];
            i -= 2;
        }
        return ret;
    }
};
