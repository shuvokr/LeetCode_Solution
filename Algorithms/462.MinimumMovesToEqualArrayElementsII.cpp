class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        if(nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        int mid = nums[ nums.size() >> 1 ], ret = 0;
        
        for(int i = 0; i < nums.size(); i++)
            ret += abs(nums[i] - mid);
        
        return (int)ret;
    }
};
