// https://leetcode.com/problems/repeated-substring-pattern/#/solutions
class Solution {
public:
    string addBinary(string a, string b) 
    {
        int sum = 0, ind = 0, carry = 0, lenA = a.size() - 1, lenB = b.size() - 1;
        string ret;
        while(lenA > -1 || lenB > -1)
        {
            if(lenA > -1 && lenB > -1)
            {
                sum = a[lenA--] + b[lenB--] + carry - 96;
                ret += sum == 0 || sum == 2 ? '0' : '1';
                carry = sum == 2 || sum == 3 ? 1 : 0;
            }
            else if(lenA > -1)
            {
                sum = a[lenA--] + carry - 48;
                ret += sum == 0 || sum == 2 ? '0' : '1';
                carry = sum == 2 || sum == 3 ? 1 : 0;
            }
            else
            {
                sum = b[lenB--] + carry - 48;
                ret += sum == 0 || sum == 2 ? '0' : '1';
                carry = sum == 2 || sum == 3 ? 1 : 0;
            }
        }
        if(carry) ret += carry + 48;
        int x = 0, y = ret.size() - 1;
        while(x < y) 
        {
            char ch = ret[x];
            ret[x] = ret[y];
            ret[y] = ch;
            x++; y--;
        }
        cout << ret << endl;
        return ret;
    }
};
