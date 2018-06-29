// Link: https://leetcode.com/problems/next-greater-element-i/description/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int len1 = findNums.size(), len2 = nums.size();
        vector<int> ret;
        for(int i = 0; i < len1; i++)
        {
            bool mark = true;
            for(int j = 0; j < len2 && mark; j++)
                if(nums[j] == findNums[i])
                    for(int k = j + 1; k < len2; k++)  
                        if(nums[k] > findNums[i])
                        {
                            ret.push_back(nums[k]); 
                            mark = false; 
                            k = len2;
                        }
            if(mark) ret.push_back(-1);
        }
        return ret;
    }
};
