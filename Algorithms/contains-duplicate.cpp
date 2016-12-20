//Problem Description: https://leetcode.com/problems/contains-duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> uMap;
        for(int i = 0; i < nums.size(); i++)
        {
            uMap[ nums[ i ] ]++;
            if(uMap[ nums[ i ] ] > 1) return true;
        }
        return false;
    }
};
