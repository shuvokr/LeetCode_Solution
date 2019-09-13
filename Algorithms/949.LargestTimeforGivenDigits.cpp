class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int max = 23 * 60 + 60, H, M, ret = -1;
        vector<int> res;
        sort(A.begin(), A.end());
        do {
            
            H = A[0] * 10 + A[1];
            M = A[2] * 10 + A[3];
            if(H < 24 && M < 60) {
                H = H * 60 + M;
                if(H < max && H > ret) {
                    ret = H;
                    res = A;
                }
            }
            
        } while(next_permutation(A.begin(), A.end()));
        if(ret == -1) return "";
        string str = doit(res[0]) + doit(res[1]) + ":" + doit(res[2]) + doit(res[3]);
        return str;
    }
    string doit(int a) {
        switch (a) {
            case 0: return "0";
            case 1: return "1";
            case 2: return "2";
            case 3: return "3";
            case 4: return "4";
            case 5: return "5";
            case 6: return "6";
            case 7: return "7";
            case 8: return "8";
            case 9: return "9";
            default: break;
        }
        return 0;
    }
};
