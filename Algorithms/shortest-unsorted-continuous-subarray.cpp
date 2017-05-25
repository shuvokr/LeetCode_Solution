// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/#/description
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector <int> v = nums;
        sort(v.begin(), v.end());
        int len = v.size();
        int i = 0;
        while(i < len && nums[ i ] == v[ i ]) i++;
        
        int j = len - 1;
        while(j > -1 && nums[ j ] == v[ j ]) j--;
        if(j < i) return 0;
        else return (j - i) + 1;
    }
};
