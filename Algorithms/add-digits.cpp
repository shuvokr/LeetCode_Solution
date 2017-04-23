//Problem Description: https://leetcode.com/problems/add-digits
class Solution {
public:
    int addDigits(int num) {
        //cout << (int)log10(num) + 1 << endl;
        while((int)log10(num) + 1 > 1)
        {
            int tmp = 0;
            while( num )
            {
                tmp += (num % 10);
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};
