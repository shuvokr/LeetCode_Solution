// https://leetcode.com/problems/total-hamming-distance/#/description
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) 
    {
        int len = nums.size(), ret = 0;
        if(len < 2) return 0;
        
        int one[ 31 ], zero[ 31 ];
        for(int i = 0; i < 31; i++)
            one[i] = zero[i] = 0;
        
        for(int i = 0, tmp, ind; i < len; i++)
        {
            ind = 0;
            tmp = nums[ i ];
            while(tmp)
            {
                int x = tmp&1;
                tmp >>= 1;
                x ? one[ind]++ : zero[ind]++;
                ind++;
            }
            for(int j = ind; j < 31; j++)
                zero[j]++;
        }
        for(int i = 0; i < 31; i++)
            ret += one[i] * zero[i];
        return ret;
    }
};
