//Problem Description: https://leetcode.com/problems/remove-duplicates-from-sorted-array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it = unique(nums.begin(), nums.end());
        nums.resize( std::distance(nums.begin(),it) );
        return nums.size();
    }
};
