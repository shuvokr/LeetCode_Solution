// https://leetcode.com/contest/weekly-contest-96/problems/boats-to-save-people/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ret = 0, a = 0, b = people.size() - 1;
        sort(people.begin(), people.end());
        while(a <= b)
        {
            if(people[a] + people[b] <= limit) ret++, a++, b--;
            else ret++, b--;
        }
        return ret;
    }
};
