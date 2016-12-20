//Problem Description: https://leetcode.com/problems/move-zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int zero = 0, ind = 0, len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(!nums[ i ]) 
            {
                zero++;
                continue;
            }
            nums[ ind++ ] = nums[ i ];
        }
        len--;
        while( zero )
        {
            nums[ len-- ] = 0;
            zero--;
        }
    }
};
