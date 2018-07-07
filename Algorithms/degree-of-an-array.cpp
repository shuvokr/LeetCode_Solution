// Link: https://leetcode.com/problems/degree-of-an-array/description/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size(), mx = -1, f[ 50002 ], p[ 50002 ], ans = 50005;
        memset(p, -1, sizeof p);
        memset(f, 0, sizeof f);
        for(int i = 0; i < len; i++)
            f[ nums[i] ]++,
            p[ nums[i] ] = p[ nums[i] ] == -1 ? i : p[ nums[i] ],
            mx = mx < f[ nums[i] ] ? f[ nums[i] ] : mx;
        for(int i = len - 1; i > -1; i--)
        {
            if(f[ nums[i] ] == mx)
            {
                int sz = i - p[ nums[i] ] + 1;
                ans = ans > sz ? sz : ans;
                f[ nums[i] ] = -1;
            }
        }
        return ans;
    }
};
