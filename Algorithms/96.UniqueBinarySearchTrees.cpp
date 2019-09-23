class Solution {
public:
    int numTrees(int n)
    {
        vector<int>v(n + 1, 0);
        v[ 0 ] = v[ 1 ] = 1;
        for (int i = 2; i <= n; i++) {
            int num = 0;
            for (int j = 1; j <= i; j++)
                num += v[j - 1] * v[i - j];
            v[ i ] = num;
        }
        return v[ n ];
    }
};
