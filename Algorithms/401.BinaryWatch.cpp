class Solution {
public:
    vector<string> ret;
    vector<string> readBinaryWatch(int num) {
        if(num == 0) {
            ret.push_back("0:00");
            return ret;
        }
        solve(0, num, 0);
        return ret;
    }
    void solve(int n, int p, int bitP) {
        if(p == 0) {
            int h = 0, m = 0;
            int H[] = {32, 16, 8, 4, 2, 1};
            for(int i = 0; i < 4; i++) {
                if(check(n, i)) h += H[i + 2];
            }
            for(int i = 4; i < 10; i++) {
                if(check(n, i)) m += H[i - 4];
            }
            if(h > 11 || m > 59) return;
            string s = to_string(m);
            if(m < 10) s = "0" + to_string(m);
            string str = to_string(h) + ":" + s;
            ret.push_back(str);
            return;
        }
        if(n > 1023 || bitP == 10) return;
        
        solve(bitOn(n, bitP), p - 1, bitP + 1);
        solve(n, p, bitP + 1);
    }
    int bitOn(int n, int p) {
        return n | (1 << p);
    }
    int check(int n, int p) {
        return n & (1 << p);
    }
};
