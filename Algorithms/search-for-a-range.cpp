//Problem Description: https://leetcode.com/problems/search-for-a-range
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>::iterator low, up;
        low = std::lower_bound(nums.begin(), nums.end(), target);
        up = std::upper_bound(nums.begin(), nums.end(), target);
        vector <int> ret;
        int lBound = low - nums.begin(), uBound = up - nums.begin();
        if(nums[ lBound ] == target)
        {
            ret.push_back(lBound);
            ret.push_back(uBound - 1);
        }
        else
        {
            ret.push_back(-1);
            ret.push_back(-1);
        }
        return ret;
    }
};
