//Problem Description: https://leetcode.com/problems/continuous-subarray-sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, mod = 0;
        if(!k)
        {
            for(int i = 1; i < nums.size(); i++)
                if(!nums[ i ] && !nums[i - 1]) return true;
            return false;
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[ i ];
            mod = sum % k;
            if(!mod && i) return true;
            if(mp.find(mod) == mp.end()) mp[ mod ] = i;
            else if(i - mp[ mod ] > 1) return true;
        }
        return false;
    }
};
