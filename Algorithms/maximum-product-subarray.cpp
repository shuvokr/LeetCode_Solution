// https://leetcode.com/problems/maximum-product-subarray/#/description
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ret = -2147483648, len = nums.size(), s = 0, e = 0, totf, totb, lf, lb, zero = 0;
        while(s < len)
        {
            while(nums[e] != 0 && e < len) e++;
            zero = e < len && nums[e] == 0 ? 1 : zero;
            if(s == e)
            {
                s++; e++; continue;
            }
            totf = totb = 1;
            lf = lb = -2147483648;
            for(int i = s, k = e - 1; i < e; i++)
            {
                totf *= nums[i];
                lf = lf < totf ? totf : lf;
                totb *= nums[k--];
                lb = lb < totb ? totb : lb;
            }
            ret = lb > lf ? ret < lb ? lb : ret : ret < lf ? lf : ret;
            e++;
            s = e;
        }
        ret = ret < 0 ? zero ? 0 : ret : ret;
        return ret;
    }
};
