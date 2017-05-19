// https://leetcode.com/problems/beautiful-arrangement/#/description
bool mamo[ 16 ] = {false};
class Solution {
public:
    int tot = -1;
    int countArrangement(int N) {
        if(tot == -1) tot = N;
        if(N == 0) return 1;
        int a = 0, b = 0;
        bool mark = true;
        for(int i = 1; i <= tot; i++)
        {
            if(!mamo[ i ] && i % N == 0)
            {
                mark = false;
                mamo[ i ] = true;
                a += countArrangement(N - 1);
                mamo[ i ] = false;
            }
            if(i != N && !mamo[i] && N%i == 0)
            {
                mark = false;
                mamo[ i ] = true;
                a += countArrangement(N - 1);
                mamo[ i ] = false;
            }
        }
        if(mark) return 0;
        return a;
    }
};
