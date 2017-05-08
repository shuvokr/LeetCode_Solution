//Problem Description: https://leetcode.com/problems/subarray-sum-equals-k
class Solution {
public:
    long long subarraySum(vector<int>& nums, int k) 
    {
        long long ret = 0;
        unordered_map<int, int> mp;
        mp[ nums[0] ]++;
        for(int i = 1; i < nums.size(); i++) 
        {
            nums[i] += nums[i - 1];
            mp[ nums[i] ]++;
        }
        ret = mp[k];
        for(int i = 0; i < nums.size(); i++)
        {
            int tmp = nums[i];
            mp[ tmp ]--;
            tmp += k;
            ret += mp[ tmp ];
            //cout << i << " " << tmp << " " <<mp[ tmp ] << endl;
        }
        return ret;
    }    
};
