//Problem Description: https://leetcode.com/problems/count-primes
class Solution {
public:
    int countPrimes(int n) {
        return primeList(n);
    }
    int primeList(int pr)
    {
        if(pr < 3) return 0;
        int ind;
        bool mark[ pr ];
        memset(mark, false, sizeof mark);
        for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
        for(int i = 3, sq = sqrt( pr ); i <= sq; i += 2)
            if(mark[ i ])
                for(int j = i * i; j < pr; j += i + i) mark[ j ] = false;
        int ret = pr > 2 ? 1 : 0;
        for(int i = 3; i < pr; i += 2)
            if(mark[ i ]) ret++;
        return ret;
    }
};
