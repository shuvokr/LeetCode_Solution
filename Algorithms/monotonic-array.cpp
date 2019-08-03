// Link : https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true, dec = true;
        int a = -100001, b = 100001;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] < a) inc = false;
            else a = A[i];
            
            if(A[i] > b) dec = false;
            else b = A[i];
            i = !inc && !dec ? A.size() : i;
        }
        return inc | dec;
    }
};
