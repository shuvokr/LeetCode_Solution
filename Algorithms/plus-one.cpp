// https://leetcode.com/problems/plus-one/description/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret; int carry = 1;
        for(int i = digits.size()-1, t; i > -1; i--)
        {
            t = digits[i] + carry;
            carry = t < 10 ? 0 : 1;
            t = t < 10 ? t : 0;
            ret.push_back(t);
        }
        if(carry) ret.push_back(1);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
