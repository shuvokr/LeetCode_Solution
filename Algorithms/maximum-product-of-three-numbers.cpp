//https://leetcode.com/problems/maximum-product-of-three-numbers/#/description
class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int len = nums.size(), array[6] = {-1001, -1001, -1001, 1001, 1001, 1001}, z = 0;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] > 0)
            {
                if(array[0] < nums[i]) array[2] = array[1], array[1] = array[0], array[0] = nums[i];
                else if(array[1] < nums[i]) array[2] = array[1], array[1] = nums[i];
                else if(array[2] < nums[i]) array[2] = nums[i];
            }
            else if(nums[i] < 0)
            {
                if(array[3] > nums[i]) array[5] = array[4], array[4] = array[3], array[3] = nums[i];
                else if(array[4] > nums[i]) array[5] = array[4], array[4] = nums[i];
                else if(array[5] > nums[i]) array[5] = nums[i];
            }
            else z++;
        }
        if(array[3] == 1001) array[3] = array[4] = array[5] = -1001;
        else if(array[4] == 1001) array[4] = array[5] = -1001;
        else if(array[5] == 1001) array[5] = -1001;
        
        if(len - z < 3) return 0;
        else
        {
            sort(array, array + 6);
            int p = 0;
            while(array[p] == -1001) p++; cout << array[p] << endl;
            int ret = array[p] * array[p+1] * array[5] > array[3] * array[4] * array[5] ? array[p] * array[p+1] * array[5] :
                array[3] * array[4] * array[5];
            return ret = ret < 0 ? z ? 0 : ret : ret;
        }
    }
};
