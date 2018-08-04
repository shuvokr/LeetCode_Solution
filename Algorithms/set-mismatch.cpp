// https://leetcode.com/problems/set-mismatch/description/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size(), tmp;
        bool mark[ len+1 ];
        memset(mark, false, sizeof mark);
        for(int i = 0; i < len; i++)
            if(mark[nums[i]]) tmp = nums[i];
            else mark[nums[i]] = true;
        nums.clear();
        nums.push_back(tmp);
        for(int i = 0; i < len; i++)
            if(!mark[i + 1])
            {
                nums.push_back(i + 1);
                return nums;
            }
    }
};
