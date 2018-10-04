https://leetcode.com/problems/sort-array-by-parity/description/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ret;
        
        for(int i= 0; i < A.size(); i++)
            if(!(A[i]&1)) ret.push_back(A[i]);
        
        for(int i= 0; i < A.size(); i++)
            if(A[i]&1) ret.push_back(A[i]);
        
        return ret;
    }
};
