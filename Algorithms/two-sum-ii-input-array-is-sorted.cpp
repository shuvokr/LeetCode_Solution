// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/#/description
class Solution {
    vector<int>ret; 
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPoint = 0, rightPoint = numbers.size() - 1;
        while(leftPoint < rightPoint)
        {
            leftPoint += numbers[leftPoint] + numbers[rightPoint] < target ? 1 : 0;
            rightPoint -= numbers[leftPoint] + numbers[rightPoint] > target ? 1 : 0;
            if(numbers[leftPoint] + numbers[rightPoint] == target) 
            {
                ret.push_back(leftPoint+1);ret.push_back(rightPoint+1);
                return ret;
            }
        }
        return ret;
    }
};
