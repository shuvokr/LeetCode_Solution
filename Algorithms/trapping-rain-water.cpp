// https://leetcode.com/problems/trapping-rain-water/#/description
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int ret = 0, len = height.size();
        if(len < 3) return 0;
        int fnt[len], bck[len];
        fnt[0] = height[0]; bck[len - 1] = height[len - 1];
        for(int i = 1; i < len; i++)
        {
            fnt[i] = fnt[i - 1] > height[i] ? fnt[i - 1] : height[i];
            bck[len-i-1] = bck[len-i] > height[len-i-1] ? bck[len-i] : height[len-i-1];
        }
        for(int i = 1; i < len - 1; i++) ret += fnt[i-1] > height[i] && bck[i+1] > height[i] ? min(fnt[i-1], bck[i+1]) - height[i] : 0;
        return ret;
    }
};
