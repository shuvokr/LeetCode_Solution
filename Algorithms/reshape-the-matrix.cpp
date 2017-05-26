// https://leetcode.com/problems/reshape-the-matrix/#/description
class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(), col = nums[0].size();
        if(r * c != row * col) return nums;
        else
        {
            vector< vector<int> >v;
            v.assign(r, vector<int>());
            int a = 0, b = 0;
            for(int i = 0; i < r; i++)
                for(int j = 0; j < c; j++)
                {
                    v[i].push_back(nums[ a ][ b ]);
                    b++;
                    if(b == col) a++, b = 0;
                }
            return v;
        }
    }
};
