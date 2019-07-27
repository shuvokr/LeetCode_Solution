// Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array
// Tag : repetation check

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int len = A.size();
        bool mamo[10001];
        memset(mamo, false, sizeof mamo);
        for(int i = 0; i < len ; i++) {
            if(mamo[A[i]]) return A[i];
            else mamo[A[i]] = true;
        }
        return 0;
    }
};
