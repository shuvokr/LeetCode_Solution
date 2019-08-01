// Link : https://leetcode.com/problems/powerful-integers

class Solution {
public:
    template <class T> T power ( T a, T p ) { T res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ret;
        for(int i = 0; ; i++) {
            long long a  = power((long long)x, (long long)i);
            if(a > bound) break;
            for(int j = 0; ; j++) {
                long long b = power((long long)y, (long long)j);
                if(a + b > bound) break;
                ret.push_back(a + b);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        sort(ret.begin(), ret.end());
        ret.erase( unique( ret.begin(), ret.end() ), ret.end() );
        return ret;
    }
};
