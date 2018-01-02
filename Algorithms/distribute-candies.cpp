// https://leetcode.com/problems/distribute-candies/description/

class Solution {
public:
    int distributeCandies(vector<int>& c) {
        int x = 0, xx = c.size(), xxx = xx >> 1;
        unordered_map<int, bool> mp;
        for(int i = 0; i < xx && xxx; i++)
        {
            x += mp.find(c[i]) == mp.end() && xxx ? 1 : 0;
            xxx -= mp.find(c[i]) == mp.end();
            mp[c[i]] = true;
        }
        return x;
    }
};
