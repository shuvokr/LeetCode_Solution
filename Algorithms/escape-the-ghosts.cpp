//https://leetcode.com/problems/escape-the-ghosts/description/

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int ck = abs(target[0]) + abs(target[1]), mn = 1000000001;
        for(int i = ghosts.size() - 1, tmp; mn > ck && i > -1; i--)
        {
            tmp = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
            mn = mn < tmp ? mn : tmp;
        }
        return mn > ck;
    }
};
