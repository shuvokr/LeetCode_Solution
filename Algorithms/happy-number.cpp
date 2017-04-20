//Problem Description: https://leetcode.com/problems/happy-number
class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        map<int, bool> mp;
        mp.clear();
        
        mp[ n ] = true;
        while(true)
        {
            int tot = 0, t;
            while(n)
            {
                t= (n % 10);
                tot += t*t;
                n /= 10;
            }
            //cout << tot << " ";
            if(mp.find(tot) != mp.end()) return false;
            n = tot;
            if(n == 1) return true;
            mp[ n ] = true;
        }
    }
};
