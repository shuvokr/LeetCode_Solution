//Problem Description: https://leetcode.com/problems/arithmetic-slices/#/description
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        long long len = A.size(), dif[ len ];
        for(int i = 1; i < len; i++)
            dif[i] = A[ i ] - A[i - 1];
        long long ans = 0;
        for(int i = 1; i < len; i++)
        {
            long long diff = dif[ i ], cou = 0;
            while(i < len && dif[ i ] == diff)
                i++, cou++;
            i--;
            ans += cou > 1 ? ((cou * (cou - 1)) / 2LL) : 0;
        }
        return (int)ans;
    }
};
