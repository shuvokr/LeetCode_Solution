template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
class Solution {
public:
    int maximumSwap(int num) {
        string digts = toString(num);
        int ret = num;
        for(int i = 0; i < digts.size(); i++)
            for(int j = i + 1; j < digts.size(); j++) {
                string str = digts;
                swap(str[i], str[j]);
                int conNum = atoi(str.c_str());
                ret = max(ret, conNum);
            }
        return ret;
    }
};
