// Link : https://leetcode.com/problems/sort-array-by-parity-ii/
// Sort

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odd, even;
        int len = A.size();
        for(int i = 0; i < len; i++)
            if(A[i]&1) odd.push_back(A[i]);
            else even.push_back(A[i]);
        A.clear(); len >>= 1;
        for(int i = 0; i < len; i++) {
            A.push_back(even[i]);
            A.push_back(odd[i]);
        }
        return A;
    }
};
