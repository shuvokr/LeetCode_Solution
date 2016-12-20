//Problem Description: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector <int> tmp, ret;
        for(int i = 0; i < nums.size(); i++) tmp.push_back(1);
        for(int i = 0; i < nums.size(); i++) tmp[ nums[ i ] - 1 ] = 0;
        for(int i = 0; i < tmp.size(); i++)
            if(tmp[ i ]) ret.push_back(i + 1);
        return ret;
    }
};
