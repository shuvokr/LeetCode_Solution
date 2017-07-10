// https://leetcode.com/problems/container-with-most-water/#/description
class Solution {
public:
    int maxArea(vector<int>& h) 
    {
        int mx = -1, left = 0, right = h.size() - 1, ret = 0;
        
        while(left < right)
        {
            if(mx < h[left])
            {
                mx = h[left];
                while(left < right && h[right] <= mx) ret = ret < (right - left) * h[right] ? (right - left) * h[right] : ret, right--;
            }
            else left++;
        }
        
        left = 0; right = h.size() - 1; mx = -1;
        while(left < right)
        {
            if(mx < h[right])
            {
                mx = h[right];
                while(left < right && h[left] <= mx) ret = ret < (right - left) * h[left] ? (right - left) * h[left] : ret, left++;
            }
            else right--;
        }
        
        return ret;
    }
};
