// https://leetcode.com/problems/add-strings/description/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret = "";
        int tmp, carry = 0, a = num1.size() - 1, b = num2.size() - 1;
        while(a > -1 || b > -1)
        {
            tmp = a == -1 ? num2[b--] - 48 : b == -1 ? num1[a--] - 48 : num1[a--] + num2[b--] - 96;
            tmp += carry;
            carry = tmp < 10 ? 0 : 1;
            tmp = tmp < 10 ? tmp : tmp - 10;
            ret = ret + char(tmp + 48);
        }
        if(carry) ret = ret + char(49);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
