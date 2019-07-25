// Link: https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int len, mamo[366][4];
    vector<int> allDays, dayCost;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        len = days.size();
        allDays = days; dayCost = costs;
        memset(mamo, -1, sizeof mamo);
        return min(DP(0, 0), min(DP(0, 1), DP(0, 2)));
    }

    int DP(int pos, int cost) {
        if(pos >= len) return 0;
        
        int &ret = mamo[pos][cost];
        if(ret != -1) return ret;
        ret = 1000000001;

        if(!cost) {

            int i = pos + 1;
            ret = min(ret, dayCost[0] + DP(i, 0));
            ret = min(ret, dayCost[0] + DP(i, 1));
            ret = min(ret, dayCost[0] + DP(i, 2));
        }
        else if(cost == 1) {

            int ck = allDays[pos] + 7 - 1, i = pos + 1;
            while(i < len && ck >= allDays[i]) i++;
            ret = min(ret, dayCost[1] + DP(i, 0));
            ret = min(ret, dayCost[1] + DP(i, 1));
            ret = min(ret, dayCost[1] + DP(i, 2));
        }
        else {

            int ck = allDays[pos] + 30 - 1, i = pos + 1;
            while(i < len && ck >= allDays[i]) i++;
            ret = min(ret, dayCost[2] + DP(i, 0));
            ret = min(ret, dayCost[2] + DP(i, 1));
            ret = min(ret, dayCost[2] + DP(i, 2));
        }
        return ret;
    }
};
