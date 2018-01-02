// https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long totalSum = 0LL, result = 0LL, maxResult = 0LL;
        int lengthN = A.size();
        for(int i = 0; i < lengthN; i++) totalSum += A[i], result += i * A[i];
        maxResult = result;
        for(int i = 1; i < lengthN; i++)
        {
            result = result - (totalSum - A[i - 1]) + (A[i - 1] * (lengthN - 1));
            maxResult = maxResult < result ? result : maxResult;
        }
        return (int)maxResult;
    }
};

/*
4 3 2 6
4 7 9 15
15 11 8 6

25 - 11 + 12 = 26
26 - 12 + 9 = 23
23 - 13 + 6 = 16
*/
