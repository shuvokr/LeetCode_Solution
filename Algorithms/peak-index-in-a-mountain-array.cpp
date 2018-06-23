// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int len = A.size();
        for(int i = 1; i < len; i++)
            if(A[i-1] < A[i] && A[i] > A[i + 1]) return i;
    }
};
