// Link: https://leetcode.com/problems/maximize-distance-to-closest-person/description/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size(), dis[len], answer = -1, i = 0;
        memset(dis, 0, sizeof dis);
        if(!seats[0]) 
        {
            dis[0] = 1;
            for(i = 1; !seats[i]; i++) dis[i] = dis[i - 1] + 1;
            if(i == len - 1) return dis[i - 1];
            answer = dis[i - 1];
        }
        i++;
        
        for(; i < len; i++)
            dis[i] = seats[i] ? 0 : dis[i - 1] + 1;
        for(i = 0; i < len; i++) cout << dis[i] << " "; puts("");
        answer = answer < dis[len - 1] ? dis[len - 1] : answer;
        for(i = len - 1; !seats[i]; i--);
        i--;
        if(i < 0) return answer;
        for(;i > -1; i--)
        {
            if(!dis[i]) continue;
            dis[i] = dis[i + 1] + 1 < dis[i] ? dis[i + 1] + 1 : dis[i];
            answer = answer < dis[i] ? dis[i] : answer;
        }
        return answer;
    }
};
