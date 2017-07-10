// https://leetcode.com/problems/rotate-array/#/description
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        vector<int>::iterator it;
        int len = nums.size();
        k %= len;
        while(k--)
        {
            it = nums.begin();
            nums.insert(it, nums[len-1]);
            nums.pop_back();
        }
    }
};
