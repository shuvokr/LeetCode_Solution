// https://leetcode.com/problems/fizz-buzz/description/

class Solution {
    template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
public:
    vector<string> fizzBuzz(int n) {
        vector <string> ret;
        for(int i = 1; i <= n; i++)
        {
            if(i % 15 == 0) ret.push_back("FizzBuzz");
            else if(i % 5 == 0) ret.push_back("Buzz");
            else if(i % 3 == 0) ret.push_back("Fizz");
            else ret.push_back(toString(i));
        }
        return ret;
    }
};
