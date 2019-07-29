// Link : https://leetcode.com/problems/smallest-range-i/

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int ret = 0, mx = -10001, mn = 10001, len = A.size();
        for(int i = 0; i < len; i++) {
            mx = mx < A[i] ? A[i] : mx;
            mn = mn < A[i] ? mn : A[i];
        }
        int difference = mx - mn;
        ret = (K << 1) < difference ? difference - (K << 1) : 0;
        return ret;
    }
};
