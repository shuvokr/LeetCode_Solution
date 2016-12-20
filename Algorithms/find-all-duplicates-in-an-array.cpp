//Problem Description: https://leetcode.com/problems/find-all-duplicates-in-an-array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        int len = nums.size(), mark[ len + 2 ];
        memset(mark, 0, sizeof mark);
        for(int i = 0; i < len; i++) mark[ nums[ i ] - 1 ]++;
        vector <int> ret;
        for(int i = 0; i < len; i++)
            if(mark[ i ] == 2) ret.push_back(i+1);
        return ret;
    }
};
