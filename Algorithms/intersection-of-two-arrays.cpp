// https://leetcode.com/problems/intersection-of-two-arrays/#/description
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, bool> mp;
        for(int i = 0; i < nums1.size(); i++) mp[ nums1[i] ] = true;
        vector<int> ret;
        for(int i = 0; i < nums2.size(); i++) 
            if(mp.find(nums2[i]) != mp.end()) { ret.push_back(nums2[ i ]); mp.erase( nums2[ i ] ); }
        return ret;
    }
};
