// Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        bool prime[ 21 ];
        int answer = 0;
        memset(prime, false, sizeof prime);
        prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = true;
        R++;
        for(int i = L; i < R; i++)
        {
            int bitCount = 0;
            for(int j = i; j ; j >>= 1) bitCount += (j&1);
            answer += prime[bitCount];
        }
        return answer;
    }
};
