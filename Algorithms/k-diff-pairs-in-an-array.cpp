//Problem Description: https://leetcode.com/problems/k-diff-pairs-in-an-array
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[ j ] - nums[ i ] == k) 
                {
                    ret++;
                    j = nums.size();
                }
                else if(nums[ j ] - nums[ i ] > k) j = nums.size();
                if((!k && nums[i] == nums[j])) break;
            }
            int x = i;
            while(x < nums.size() && nums[ i ] == nums[ x ]) x++; i = x - 1;
        }
        return ret;
    }
};
