// Link: https://leetcode.com/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cou5 = 0, cou10 = 0, len = bills.size();
        for(int i = 0; i < len; i++)
        {
            if(bills[i] == 20)
            {
                if(cou10) cou10--, cou5--;
                else cou5 -= 3;
            }
            else if(bills[i] == 10) cou5--, cou10++;
            else cou5++;
            if(cou5 < 0 || cou10 < 0) return false;
        }
        return true;
    }
};
