// Link : https://leetcode.com/problems/sum-of-even-numbers-after-queries

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector <int> res;
        int len = A.size(), sum = 0;
        for(int i = 0; i < len; i++) sum += (A[i]&1) ? 0 : A[i];
        for(int i = 0; i < queries.size(); i++) {
            int val = queries[i][0], index = queries[i][1], valueA = A[ index ];
            if((val&1) == (valueA&1)) {
                sum += val;
                sum += (valueA&1) ? valueA : 0;
                A[ index ] += val;
                res.push_back(sum);
            }
            else {
                sum -= (!(valueA&1)) ? valueA : 0;
                A[ index ] += val;
                res.push_back(sum);
            }
        }
        return res;
    }
};
