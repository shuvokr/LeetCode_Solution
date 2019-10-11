class Solution {
    double mamo[101][101][101];
    double sum[100];
    int len;
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        len = A.size();
        sum[0] = (double)A[0];
        for(int i = 1; i < A.size(); i++)
            sum[i] = sum[i - 1] + (double)A[i];
        for(int i = 0; i < A.size(); i++)
            for(int j = i; j < A.size(); j++)
                for(int k = 0; k <= K; k++)
                    mamo[i][j][k] = -1;
        return DP(0, 0, K);
    }
    double DP(int partitionFrom, int partitionTo, int K) {
        if(K == 0 && partitionFrom == len) return 0.0;
        if(K < 0 || partitionFrom > partitionTo) return -10000000.0;
        if(partitionFrom >= len || partitionTo >= len) return -10000000.0;
        
        if(mamo[partitionFrom][partitionTo][K] != -1) 
            return mamo[partitionFrom][partitionTo][K];
        
        double val = sum[partitionTo];
        if(partitionFrom) val -= sum[partitionFrom - 1];
        double dif = (partitionTo - partitionFrom + 1);
        val /= dif;
                
        mamo[partitionFrom][partitionTo][K] = max(val + DP(partitionTo + 1, partitionTo + 1, K - 1), DP(partitionFrom, partitionTo + 1, K));
        return mamo[partitionFrom][partitionTo][K];
    }
};
