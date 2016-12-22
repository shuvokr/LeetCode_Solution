//Problem Description: https://leetcode.com/problems/range-sum-query-immutable
class NumArray 
{
public:
    vector<int> tmp;
    NumArray(vector<int> &nums) 
    {
        tmp = nums;
        for(int i = 1; i < tmp.size(); i++) tmp[ i ] += tmp[i - 1];
    }

    int sumRange(int i, int j) 
    {
        int ret = i ? tmp[ j ] - tmp[i - 1] : tmp[ j ];
        return ret;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
