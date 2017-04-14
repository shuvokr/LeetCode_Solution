//Problem Description: https://leetcode.com/problems/4sum-ii
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < B.size(); j++) mp[ A[i] + B[j] ]++;
        int ret = 0;
        for(int i = 0; i < C.size(); i++)
            for(int j = 0; j < D.size(); j++)
            { 
                int tmp = C[i] + D[j];
                tmp *= -1;
                if(mp.find( tmp ) != mp.end()) ret += mp[ tmp ];
            }
        return ret;
    }
};
