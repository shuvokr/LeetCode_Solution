// https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int s = nums.size(), mn = s>>1, ret = 0, mx = -(1<<31);
        unordered_map<int, int> um;
        for(int i = 0; i < s; i++)
        {
            um[nums[i]]++;
            if(um[nums[i]] > ret)
            {
                ret = um[nums[i]]; mx = nums[i];
            }
        }
        return mx;
    }
};
